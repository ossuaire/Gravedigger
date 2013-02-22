#include "ALeft.hpp"

ALeft::ALeft(Character * _parent,
	     const sf::Int64 _moduloTime) : AAnimation(_parent,_moduloTime) {
}

void ALeft::execute(const sf::Int64 elapsed) {
  // TODO: Verif' they are existing components
  // #1 get all components
  CSpeed * speed;
  speed = (CSpeed *) parent->getComponent("Speed");
  CAcceleration * acceleration;
  acceleration = (CAcceleration *) parent->getComponent("Acceleration");
  CPosition * position = (CPosition *) parent->getComponent("Position");
  CSprite * sprite = (CSprite *) parent->getComponent("Sprite");
  sprite->setDirection("left");

  if (speed->getHSpeed() > 1.4) {
    // #2a go back to 0
    speed->setHSpeed((speed->getHSpeed())-((float)(speed->getHSpeed())/8.0));
    position->setX((position->getX())+(speed->getHSpeed()));
    sprite->updatePosition();
  } else {
    // #2b increase speed
    speed->setHSpeed((speed->getHSpeed())-(acceleration->getHAcceleration()));
    position->setX((position->getX())+(speed->getHSpeed())); // round inf
    sprite->updatePosition();
  } 
  // #3 change sprites TODO
  // example : if elapsed > modulotime/2 then ...
  sf::Int64 temp;
  if (elapsed>getModuloTime()){
    temp = getModuloTime();
  } else {
    temp = elapsed;
  }
  int k = 0; //index to read in tab                                             
  while (temp >0) {
    ++k;
    temp = temp - getModuloTime()/getSubSprites().size();
  }
  sprite->updateSubSprite(getSubSprites().at(k-1));
  sprite->setOrigin("middle","bottom");
}
