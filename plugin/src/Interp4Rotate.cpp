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
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
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
