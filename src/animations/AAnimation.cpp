#include "AAnimation.hpp"

AAnimation::AAnimation(GameObject* _parent,
		       const sf::Int64 _moduloTime) : elapsedSum(0) {
  parent = _parent;
  moduloTime = _moduloTime;
}

AAnimation::~AAnimation() {
  // Nothing lawl
}

sf::Int64 AAnimation::getModuloTime() {
  return moduloTime;
}

sf::Int64 AAnimation::getElapsedSum() {
  return elapsedSum;
}

void AAnimation::setElapsedSum(const sf::Int64 _elapsedSum){
  elapsedSum = _elapsedSum;
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
