#include "AStand.hpp"

AStand::AStand(Character * _parent,
	       const sf::Int64 _moduloTime) : AAnimation(_parent,_moduloTime) {
}

void AStand::execute(const sf::Int64 elapsed) {
  // TODO: Verif' they are existing components
  // #1 get all components
  sf::Int64 tempElapsedSum = getElapsedSum() + elapsed;
  CSpeed * speed = (CSpeed *) parent->getComponent("Speed");
  if ((float) std::abs(speed->getHSpeed()) > 1.2) {
    CAcceleration * acceleration;
    acceleration = (CAcceleration *) parent->getComponent("Acceleration");
    CPosition *  position = (CPosition *) parent->getComponent("Position");
    CSprite * sprite = (CSprite *) parent->getComponent("Sprite");

    // #2 add value
    speed->setHSpeed((speed->getHSpeed())-((float)(speed->getHSpeed())/8.0));
    position->setX((position->getX())+(speed->getHSpeed()));
    sprite->updatePosition();
  } else {
    speed->setHSpeed(0.0);
  }

  // #3 change sprites
  // For now, only 2 sprites allowed, maybe tochange in future
  CSprite * sprite = (CSprite *) parent->getComponent("Sprite");
  if (tempElapsedSum < getModuloTime()/2){
    sprite->updateSubSprite(getSubSprites().at(0));
  } else {
    if (getSubSprites().size()>1) {
      sprite->updateSubSprite(getSubSprites().at(1));
    }
  }
  sprite->setOrigin("middle","bottom");
  setElapsedSum(tempElapsedSum%getModuloTime());
}
