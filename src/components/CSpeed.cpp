#include "CSpeed.hpp"

CSpeed::CSpeed( Character* _parent,
		const float _hSpeed,
		const float _vSpeed,
		const float _hSpeedMax,
		const float _vSpeedMax) : CComponent(_parent) {
  setHSpeed(_hSpeed);
  setVSpeed(_vSpeed);
  setHSpeedMax(_hSpeedMax);
  setVSpeedMax(_vSpeedMax);
}

float CSpeed::getHSpeed() {
  return hSpeed;
}

float CSpeed::getVSpeed() {
  return vSpeed;
}

float CSpeed::getHSpeedMax() {
  return hSpeedMax;
}

float CSpeed::getVSpeedMax() {
  return vSpeedMax;
}

void CSpeed::setHSpeed(const float _hSpeed) {
  hSpeed = _hSpeed;
}

void CSpeed::setVSpeed(const float _vSpeed) {
  vSpeed = _vSpeed;
}

void CSpeed::setHSpeedMax(const float _hSpeedMax) {
  hSpeedMax = _hSpeedMax;
}

void CSpeed::setVSpeedMax(const float _vSpeedMax) {
  vSpeedMax = _vSpeedMax;
}
