#include "AAnimation.hpp"

AAnimation::AAnimation(Character* _parent, const sf::Int64 _moduloTime) {
  parent = _parent;
  moduloTime = _moduloTime;
}

AAnimation::~AAnimation() {
  // Nothing lawl
}

sf::Int64 AAnimation::getModuloTime() {
  return moduloTime;
}

void AAnimation::addSubSprite(const sf::IntRect subSprite) {
  subSprites.push_back(subSprite);
}

std::vector<sf::IntRect> AAnimation::getSubSprites() {
  return subSprites;
}

void AAnimation::setModuloTime(const sf::Int64 _moduloTime) {
  moduloTime = _moduloTime;
}
