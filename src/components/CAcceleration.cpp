#include "CAcceleration.hpp"


CAcceleration::CAcceleration(GameObject* _parent,
			     const sf::Int64 _hAcceleration,
			     const sf::Int64 _vAcceleration) :
                             CComponent(_parent) {
  setHAcceleration(_hAcceleration);
  setVAcceleration(_vAcceleration);
}


sf::Int64 CAcceleration::getHAcceleration() {
  return hAcceleration;
}

sf::Int64 CAcceleration::getVAcceleration() {
  return vAcceleration;
}

void CAcceleration::setHAcceleration(const sf::Int64 _hAcceleration) {
  hAcceleration = _hAcceleration;
}

void CAcceleration::setVAcceleration(const sf::Int64 _vAcceleration) {
  vAcceleration = _vAcceleration;
}

