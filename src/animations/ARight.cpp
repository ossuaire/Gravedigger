#include "ARight.hpp"

ARight::ARight(Character * _parent,
	     const sf::Int32 _moduloTime) : AAnimation(_parent,_moduloTime) {
}

void ARight::execute(const sf::Int32 elapsed) {
  // TODO: Verif' they are existing components
  // #1 get all components
  CAcceleration * acceleration;
  acceleration = (CAcceleration *) parent->getComponent("Acceleration");
  CSpeed * speed = (CSpeed *) parent->getComponent("Speed");
  CPosition * position = (CPosition *) parent->getComponent("Position");
  CSprite * sprite = (CSprite *) parent->getComponent("Sprite");
  sprite->setDirection("right");

  if (speed->getHSpeed() < -1.4) {
    // #2a go back to 0                                                       
    speed->setHSpeed((speed->getHSpeed())-((float)(speed->getHSpeed())/8.0));
    position->setX((position->getX())+(speed->getHSpeed()));
    sprite->updatePosition();
  } else { 
    // #2b add values
    speed->setHSpeed((speed->getHSpeed())+(acceleration->getHAcceleration()));
    position->setX((position->getX())+ceil((speed->getHSpeed()))); // round sup
    sprite->updatePosition();
  }
  // #3 change sprites TODO
  // example : if elapsed > modulotime/2 then ...
}
