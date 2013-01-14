#include "CSpeed.hpp"

CSpeed::CSpeed( Character* _parent,
		const float _hSpeed,
		const float _vSpeed) : CComponent(_parent) {
  hSpeed = _hSpeed;
  vSpeed = _vSpeed;
}

float CSpeed::getHSpeed() {
  return hSpeed;
}

float CSpeed::getVSpeed() {
  return vSpeed;
}

void CSpeed::setHSpeed(const float _hSpeed) {
  hSpeed = _hSpeed;
}

void CSpeed::setVSpeed(const float _vSpeed) {
  vSpeed = _vSpeed;
}
