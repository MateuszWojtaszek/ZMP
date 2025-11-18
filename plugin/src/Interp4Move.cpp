#include "Interp4Move.hh"
#include <iostream>

using std::cout;
using std::endl;

extern "C" {
AbstractInterp4Command* CreateCmd(void);
const char* GetCmdName() {
  return "Move";
}
}

/*!
 * \brief
 *
 *
 */
AbstractInterp4Command* CreateCmd(void) {
  return Interp4Move::CreateCmd();
}

/*!
 *
 */
Interp4Move::Interp4Move() : _Speed_mmS(0) {}

/*!
 *
 */
void Interp4Move::PrintCmd() const {
  cout << "Move, szybkość: " << _Speed_mmS << " DługośćDrogi: " << _Distance
       << " \n";
}

/*!
 *
 */
const char* Interp4Move::GetCmdName() const {
  return ::GetCmdName();
}

/*!
 *
 */
bool Interp4Move::ExecCmd(AbstractScene& rScn, const char* sMobObjName,
                          AbstractComChannel& rComChann) {
  AbstractMobileObj* pObj = rScn.FindMobileObj(sMobObjName);
  if (!pObj)
    return false;

  // Parametry symulacji
  const int FPS = 50;
  const double step_time_us = 1000000.0 / FPS;  // np. 20000 us

  // Obliczenia czasu i kroków
  // Uwaga: _Speed_mmS w nazwie sugeruje mm/s, ale w zadaniu często jest m/s.
  // Zakładam, że wartosc jest w jednostkach zgodnych ze sceną (metry).
  double velocity = _Speed_mmS;
  double total_time_s = std::abs(_Distance / _Speed_mmS);
  int total_frames = std::ceil(total_time_s * FPS);

  double step_dist = (_Speed_mmS > 0 ? 1 : -1) * (_Distance / total_frames);

  for (int i = 0; i < total_frames; ++i) {
    // 1. Pobierz aktualną orientację (w stopniach -> na radiany)
    double roll = pObj->GetAng_Roll_deg() * M_PI / 180.0;
    double pitch = pObj->GetAng_Pitch_deg() * M_PI / 180.0;
    double yaw = pObj->GetAng_Yaw_deg() * M_PI / 180.0;

    // 2. Oblicz zmianę pozycji (ruch wzdłuż lokalnej osi OX)
    // Wzór na przesunięcie w 3D:
    double dx = step_dist * cos(pitch) * cos(yaw);
    double dy = step_dist * cos(pitch) * sin(yaw);
    double dz = step_dist * sin(pitch);

    // 3. Zaktualizuj pozycję
    Vector3D newPos = pObj->GetPosition_m();
    newPos[0] += dx;
    newPos[1] += dy;
    newPos[2] += dz;
    pObj->SetPosition_m(newPos);

    // 4. Wyślij UpdateObj
    std::stringstream ss;
    ss << "UpdateObj Name=" << sMobObjName << " Trans_m=(" << newPos[0] << ","
       << newPos[1] << "," << newPos[2] << ")\n";
    std::string msg = ss.str();
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

    // 5. Czekaj
    usleep(static_cast<useconds_t>(step_time_us));
  }
  return true;
}

/*!
 *
 */
bool Interp4Move::ReadParams(std::istream& Strm_CmdsList) {
  Strm_CmdsList >> _Speed_mmS >> _Distance;
  return !Strm_CmdsList.fail();
}

/*!
 *
 */
AbstractInterp4Command* Interp4Move::CreateCmd() {
  return new Interp4Move();
}

/*!
 *
 */
void Interp4Move::PrintSyntax() const {
  cout << "   Move  NazwaObiektu  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}
