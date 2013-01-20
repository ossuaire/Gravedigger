#include "CSpeed.hpp"

CSpeed::CSpeed( GameObject* _parent,
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
  ( _hSpeed > 0 ) ? 
    hSpeed = std::min(_hSpeed,hSpeedMax):
    hSpeed = std::max(_hSpeed,-hSpeedMax);
}

void CSpeed::setVSpeed(const float _vSpeed) {
  ( _vSpeed > 0) ?
    vSpeed = std::min(_vSpeed,vSpeedMax):
    vSpeed = std::max(_vSpeed,-vSpeedMax);
}

void CSpeed::setHSpeedMax(const float _hSpeedMax) {
  hSpeedMax = _hSpeedMax;
}

void CSpeed::setVSpeedMax(const float _vSpeedMax) {
  vSpeedMax = _vSpeedMax;
}
