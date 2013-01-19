#include "ALeft.hpp"

ALeft::ALeft(Character * _parent,
	     const sf::Int32 _moduloTime) : AAnimation(_parent,_moduloTime) {
}

void ALeft::update(const sf::Int32 elapsed) {
  // TODO: Verif' they are existing components
  // #1 get all components
  CAcceleration * acceleration;
  acceleration = (CAcceleration *) parent->getComponent("Acceleration");
  CSpeed * speed;
  speed = (CSpeed *) parent->getComponent("Speed");
  CPosition * position;
  position = (CPosition *) parent->getComponent("Position");
  
  // #2 add values
  speed->setHSpeed((speed->getHSpeed())-(acceleration->getHAcceleration()));
  position->setX((position->getX())+(speed->getHSpeed()));

  // #3 change sprites TODO
  // example : if elapsed > modulotime/2 then ...
}
