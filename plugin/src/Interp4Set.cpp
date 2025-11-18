#include "Interp4Set.hpp"
#include <iostream>

using std::cout;
using std::endl;

extern "C" {
AbstractInterp4Command* CreateCmd(void);
const char* GetCmdName() {
  return "Set";
}
}

/*!
 * \brief
 *
 *
 */
AbstractInterp4Command* CreateCmd(void) {
  return Interp4Set::CreateCmd();
}

/*!
 *
 */
Interp4Set::Interp4Set() = default;

/*!
 *
 */
void Interp4Set::PrintCmd() const {

  cout << "Set (Params: Trans=" << _TransX << "," << _TransY << "," << _TransZ
       << " Rot=" << _RotX << "," << _RotY << "," << _RotZ << ")\n";
}

/*!
 *
 */
const char* Interp4Set::GetCmdName() const {
  return ::GetCmdName();
}

/*!
 *
 */
bool Interp4Set::ExecCmd(AbstractScene& rScn, const char* sMobObjName,
                         AbstractComChannel& rComChann) {
  // 1. Znajdź obiekt na scenie
  AbstractMobileObj* pObj = rScn.FindMobileObj(sMobObjName);
  if (!pObj) {
    std::cerr << "Błąd: Nie znaleziono obiektu: " << sMobObjName << std::endl;
    return false;
  }

  // 2. Zaktualizuj parametry lokalne obiektu
  Vector3D newPos;
  newPos[0] = _TransX;
  newPos[1] = _TransY;
  newPos[2] = _TransZ;

  pObj->SetPosition_m(newPos);
  pObj->SetAng_Roll_deg(_RotX);
  pObj->SetAng_Pitch_deg(_RotY);
  pObj->SetAng_Yaw_deg(_RotZ);

  // 3. Wyślij komendę UpdateObj do serwera
  std::stringstream ss;
  ss << "UpdateObj Name=" << sMobObjName << " Trans_m=(" << _TransX << ","
     << _TransY << "," << _TransZ << ")"
     << " RotXYZ_deg=(" << _RotX << "," << _RotY << "," << _RotZ << ")\n";
  std::string msg = ss.str();
  // Sekcja krytyczna dla wysyłania
  rComChann.LockAccess();
  int socket = rComChann.GetSocket();
  const char* data = msg.c_str();
  size_t len = msg.length();
  size_t total_sent = 0;

  while (total_sent < len) {
    ssize_t sent = write(socket, data + total_sent, len - total_sent);
    if (sent < 0) {
      std::cerr << "Błąd wysyłania w ExecCmd!\n";
      break;
    }
    total_sent += sent;
  }
  rComChann.UnlockAccess();

  return true;
}

/*!
 *
 */
bool Interp4Set::ReadParams(std::istream& Strm_CmdsList) {
  Strm_CmdsList >> _TransX >> _TransY >> _TransZ >> _RotX >> _RotY >> _RotZ;
  return !Strm_CmdsList.fail();
}

/*!
 *
 */
AbstractInterp4Command* Interp4Set::CreateCmd() {
  return new Interp4Set();
}

/*!
 *
 */
void Interp4Set::PrintSyntax() const {
  cout << "   Set  NazwaObiektu  Połozenie[x y z]  Rotacja[x y z]" << endl;
}
