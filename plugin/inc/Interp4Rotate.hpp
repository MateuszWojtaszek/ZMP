#ifndef COMMAND4ROTATE_HH
#define COMMAND4ROTATE_HH
#include <istream>
#include <ostream>
#ifndef __GNUG__
#pragma interface
#pragma implementation
#endif

#include <unistd.h>
#include <cmath>
#include <sstream>
#include "AbstractInterp4Command.hh"
/*!
 * \file
 * \brief Definicja klasy Interp4Move
 *
 * Plik zawiera definicję klasy Interp4Move ...
 */

/*!
 * \brief Modeluje polecenie dla robota mobilnego, które wymusza jego ruch do przodu
 *
 *  Klasa modeluj47e ...
 */
class Interp4Rotate : public AbstractInterp4Command {
 public:
  enum class Axis { OX, OY, OZ, Unknown };

 private:
  Axis _Axis;
  double _Speed_degS;
  double _Angle_deg;

 public:
  /*!
   * \brief
   */
  Interp4Rotate();
  /*!
   * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)
   */
  virtual void PrintCmd() const override;
  /*!
   * \brief Wyświetla składnię polecenia
   */
  virtual void PrintSyntax() const override;
  /*!
   * \brief Wyświetla wartości wczytanych parametrów
   */
  virtual void PrintParams() const override {}

  /*!
   * \brief Wyświetla nazwę polecenia
   */
  virtual const char* GetCmdName() const override;

  /*!
   * \brief Wykonuje polecenie oraz wizualizuje jego realizację
   *
   * Wykonuje polecenie oraz wizualizuje jego realizację.
   * \param[in,out]  rScn - scena zawierającą obiekty mobilne,
   * \param[in]      sMobObjName - wskaźnik na nazwę lokalizującą i identyfikującą obiekt,
   * \param[in,out]  rComChann - kanał komunikacyjny z serwerem graficznym.
   * \retval true - operacja powiodła się,
   * \retval false - w przypadku przeciwnym.
   */
  virtual bool ExecCmd(AbstractScene& rScn, const char* sMobObjName,
                       AbstractComChannel& rComChann) override;
  /*!
   * \brief Czyta wartości parametrów danego polecenia
   */
  virtual bool ReadParams(std::istream& Strm_CmdsList) override;

  /*!
   * \brief
   *
   *  Ta metoda nie musi być zdefiniowna w klasie bazowej.
   */
  static AbstractInterp4Command* CreateCmd();
};

inline std::ostream& operator<<(std::ostream& os, Interp4Rotate::Axis axis) {
  switch (axis) {
    case Interp4Rotate::Axis::OX:
      os << "OX";
      break;
    case Interp4Rotate::Axis::OY:
      os << "OY";
      break;
    case Interp4Rotate::Axis::OZ:
      os << "OZ";
      break;
    case Interp4Rotate::Axis::Unknown:
      os << "Unknown";
      break;
  }
  // Zawsze zwracaj strumień, aby umożliwić łączenie wywołań
  // (np. cout << _Axis << " dalszy tekst..." << endl;)
  return os;
}

#endif
