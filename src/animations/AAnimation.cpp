#include "AAnimation.hpp"

AAnimation::AAnimation(Character* _parent, const sf::Int32 _moduloTime) {
  parent = _parent;
  moduloTime = _moduloTime;
}

AAnimation::~AAnimation() {
  // Nothing lawl
}

sf::Int32 AAnimation::getModuloTime() {
  return moduloTime;
}

void AAnimation::setModuloTime(const sf::Int32 _moduloTime) {
  moduloTime = _moduloTime;
}
