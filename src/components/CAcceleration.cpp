#include "CAcceleration.hpp"


CAcceleration::CAcceleration(GameObject* _parent,
			     const float _hAcceleration,
			     const float _vAcceleration): CComponent(_parent) {
  setHAcceleration(_hAcceleration);
  setVAcceleration(_vAcceleration);
}


float CAcceleration::getHAcceleration() {
  return hAcceleration;
}

float CAcceleration::getVAcceleration() {
  return vAcceleration;
}

void CAcceleration::setHAcceleration(const float _hAcceleration) {
  hAcceleration = _hAcceleration;
}

void CAcceleration::setVAcceleration(const float _vAcceleration) {
  vAcceleration = _vAcceleration;
}

