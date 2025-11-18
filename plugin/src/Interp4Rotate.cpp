#include "Interp4Rotate.hpp"
#include <iostream>

using std::cout;
using std::endl;

extern "C" {
AbstractInterp4Command* CreateCmd(void);
const char* GetCmdName() {
  return "Rotate";
}
}

/*!
 * \brief
 *
 *
 */
AbstractInterp4Command* CreateCmd(void) {
  return Interp4Rotate::CreateCmd();
}

/*!
 *
 */
Interp4Rotate::Interp4Rotate() = default;

/*!
 *
 */
void Interp4Rotate::PrintCmd() const {
  cout << "Rotate: Oś: " << _Axis << " szybkość kątowa: " << _Speed_degS
       << " Kąt obrotu: " << _Angle_deg << " \n";
};

/*!
 *
 */
const char* Interp4Rotate::GetCmdName() const {
  return ::GetCmdName();
}

/*!
 *
 */
bool Interp4Rotate::ExecCmd(AbstractScene& rScn, const char* sMobObjName,
                            AbstractComChannel& rComChann) {
  AbstractMobileObj* pObj = rScn.FindMobileObj(sMobObjName);
  if (!pObj)
    return false;

  const int FPS = 50;
  const double step_time_us = 1000000.0 / FPS;

  double total_time_s = std::abs(_Angle_deg / _Speed_degS);
  int total_frames = std::ceil(total_time_s * FPS);
  if (total_frames <= 0)
    total_frames = 1;
  double step_angle = _Angle_deg / total_frames;

  for (int i = 0; i < total_frames; ++i) {
    pObj->LockAccess();

    double currRoll = pObj->GetAng_Roll_deg();
    double currPitch = pObj->GetAng_Pitch_deg();
    double currYaw = pObj->GetAng_Yaw_deg();

    if (_Axis == Axis::OX) {  // Jeśli masz enum Axis
      pObj->SetAng_Roll_deg(currRoll + step_angle);
    } else if (_Axis == Axis::OY) {
      pObj->SetAng_Pitch_deg(currPitch + step_angle);
    } else if (_Axis == Axis::OZ) {
      pObj->SetAng_Yaw_deg(currYaw + step_angle);
    }

    // Budowa komendy (musimy wysłać wszystkie kąty, nawet te niezmienione)
    std::stringstream ss;
    ss << "UpdateObj Name=" << sMobObjName << " RotXYZ_deg=("
       << pObj->GetAng_Roll_deg() << "," << pObj->GetAng_Pitch_deg() << ","
       << pObj->GetAng_Yaw_deg() << ")\n";
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
    pObj->UnlockAccess();

    usleep(static_cast<useconds_t>(step_time_us));
  }
  return true;
}

/*!
 *
 */
bool Interp4Rotate::ReadParams(std::istream& Strm_CmdsList) {
  std::string axisStr;
  Strm_CmdsList >> axisStr;  // jako tymczasowy string

  if (axisStr == "OX") {
    _Axis = Axis::OX;
  } else if (axisStr == "OY") {
    _Axis = Axis::OY;
  } else if (axisStr == "OZ") {
    _Axis = Axis::OZ;
  } else {
    _Axis = Axis::Unknown;
    return false;  // Błąd, nieznana oś
  }

  Strm_CmdsList >> _Speed_degS >> _Angle_deg;
  return !Strm_CmdsList.fail();
}

/*!
 *
 */
AbstractInterp4Command* Interp4Rotate::CreateCmd() {
  return new Interp4Rotate();
}

/*!
 *
 */
void Interp4Rotate::PrintSyntax() const {
  cout << "   Rotate  NazwaObiektu  Oś  szybkość_kątowa[m/s]  kąt_obrotu"
       << endl;
}
