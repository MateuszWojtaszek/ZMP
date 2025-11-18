#pragma once
#include <string>
#include "AbstractMobileObj.hh"

class MobileObj : public AbstractMobileObj {
  std::string _Name;
  Vector3D _Position_m, _Scale, _RGB, _Shift;
  double _Ang_Roll_deg{0.0}, _Ang_Pitch_deg{0.0}, _Ang_Yaw_deg{0.0};

 public:
  MobileObj();
  /* SETTERY */
  void SetPosition_m(const Vector3D& rPos) override { _Position_m = rPos; }
  void SetName(const char* sName) override { _Name = sName; }
  void SetAng_Roll_deg(double Ang_Roll_deg) override {
    _Ang_Roll_deg = Ang_Roll_deg;
  }
  void SetAng_Pitch_deg(double Ang_Pitch_deg) override {
    _Ang_Pitch_deg = Ang_Pitch_deg;
  }
  void SetAng_Yaw_deg(double Ang_Yaw_deg) override {
    _Ang_Yaw_deg = Ang_Yaw_deg;
  }
  void SetScale(const Vector3D& rScl) { _Scale = rScl; }
  void SetRGB(const Vector3D& rRGB) { _RGB = rRGB; }
  void SetShift(const Vector3D& rShift) { _Shift = rShift; }
  /* GETTERY */
  const Vector3D& GetPosition_m() const override { return _Position_m; }
  const std::string& GetName() const override { return _Name; }
  double GetAng_Roll_deg() const override { return _Ang_Roll_deg; }
  double GetAng_Pitch_deg() const override { return _Ang_Pitch_deg; }
  double GetAng_Yaw_deg() const override { return _Ang_Yaw_deg; }
  const Vector3D& GetScale() const { return _Scale; }
  const Vector3D& GetRGB() const { return _RGB; }
  const Vector3D& GetShift() const { return _Shift; }
};