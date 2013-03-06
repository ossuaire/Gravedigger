#include "ARight.hpp"

ARight::ARight(Character * _parent,
	     const sf::Int64 _moduloTime) : AAnimation(_parent,_moduloTime) {
}

void ARight::execute(const sf::Int64 elapsed) {
  // TODO: Verif' they are existing components
  // #1 get all components
  sf::Int64 tempElapsedSum = getElapsedSum() + elapsed;
  CAcceleration * acceleration;
  acceleration = (CAcceleration *) parent->getComponent("Acceleration");
  CSpeed * speed = (CSpeed *) parent->getComponent("Speed");
  CPosition * position = (CPosition *) parent->getComponent("Position");
  CSprite * sprite = (CSprite *) parent->getComponent("Sprite");
  sprite->setDirection("right");

  if (speed->getHSpeed() < -1.2) {
    // #2a go back to 0                                                       
    speed->setHSpeed((speed->getHSpeed())-((float)(speed->getHSpeed())/8.0));
    position->setX((position->getX())+(speed->getHSpeed()));
    sprite->updatePosition();
  } else { 
    // #2b add values
    speed->setHSpeed((speed->getHSpeed())+
		     ((float)elapsed/acceleration->getHAcceleration()*
		      speed->getHSpeedMax()));
    position->setX((position->getX())+ceil((speed->getHSpeed()))); // round sup
    sprite->updatePosition();
  }

  // #3 change sprites
  sf::Int64 temp = 0;
  int k = 0; //index to read in tab
  while (temp < tempElapsedSum) {
    ++k;
    temp = temp + (getModuloTime()/getSubSprites().size());
  }
  if ((k-1)>=getSubSprites().size())
    {k=getSubSprites().size();}
  sprite->updateSubSprite(getSubSprites().at(k-1));
  sprite->setOrigin("middle","bottom");
  setElapsedSum(tempElapsedSum%getModuloTime());
}
