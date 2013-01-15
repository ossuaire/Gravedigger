#include "CAcceleration.hpp"


CAcceleration::CAcceleration(Character* _parent,
			     const float _hAcceleration,
			     const float _vAcceleration,
			     const float _hAccInc,
			     const float _vAccInc,
			     const float _hAccMax,
			     const float _vAccMax): CComponent(_parent) {
  setHAcceleration(_hAcceleration);
  setVAcceleration(_vAcceleration);
  setVAccInc(_vAccInc);
  setHAccInc(_hAccInc);
  setVAccMax(_vAccMax);
  setHAccMax(_hAccMax);
}


float CAcceleration::getHAcceleration() {
  return hAcceleration;
}

float CAcceleration::getVAcceleration() {
  return vAcceleration;
}

float CAcceleration::getVAccInc() {
  return vAccInc;
}

float CAcceleration::getHAccInc() {
  return hAccInc;
}

float CAcceleration::getVAccMax() {
  return vAccMax;
}

float CAcceleration::getHAccMax() {
  return hAccMax;
}

void CAcceleration::setHAcceleration(const float _hAcceleration) {
  hAcceleration = _hAcceleration;
}

void CAcceleration::setVAcceleration(const float _vAcceleration) {
  vAcceleration = _vAcceleration;
}

void CAcceleration::setVAccInc(const float _vAccInc) {
  vAccInc = _vAccInc;
}

void CAcceleration::setHAccInc(const float _hAccInc) {
  hAccInc = _hAccInc;
}

void CAcceleration::setVAccMax(const float _vAccMax) {
  vAccMax = _vAccMax;
}

void CAcceleration::setHAccMax(const float _hAccMax) {
  hAccMax = _hAccMax;
}

