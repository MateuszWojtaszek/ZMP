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
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
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
