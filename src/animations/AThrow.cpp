#include "AThrow.hpp"

AThrow::AThrow(GameObject * _parent,
	       const sf::Int64 _moduloTime) : AAnimation(_parent,_moduloTime) {
}

void AThrow::execute(const sf::Int64 elapsed) {
  sf::Int64 tempElapsedSum = getElapsedSum() + elapsed;

  CSpeed * speed = (CSpeed*) parent->getComponent("Speed");
  CPosition * position = (CPosition*) parent->getComponent("Position");
  CSprite * sprite = (CSprite*) parent->getComponent("Sprite");

  position->setX( position->getX() + speed->getHSpeed());
  position->setY( position->getY() + speed->getVSpeed());

  sprite->updateSubSprite(getSubSprites().at(0));
  sprite->updatePosition();
  sprite->setOrigin("middle","bottom");
  // TODO : Change sprite?
}
