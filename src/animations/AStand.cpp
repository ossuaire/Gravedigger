#include "AStand.hpp"

AStand::AStand(Character * _parent,
	     const sf::Int32 _moduloTime) : AAnimation(_parent,_moduloTime) {
}

void AStand::execute(const sf::Int32 elapsed) {
  // TODO: Verif' they are existing components
  // #1 get all components
  CSpeed * speed;
  speed = (CSpeed *) parent->getComponent("Speed");
  if ((float) std::abs(speed->getHSpeed()) > 1.0) {
    CAcceleration * acceleration;
    acceleration = (CAcceleration *) parent->getComponent("Acceleration");
    CPosition * position;
    position = (CPosition *) parent->getComponent("Position");
  
    // #2 add value
    speed->setHSpeed((speed->getHSpeed())/2);
    position->setX((position->getX())+(speed->getHSpeed()));
  } else {
    speed->setHSpeed(0.0);
  }

  // #3 change sprites TODO
  // example : if elapsed > modulotime/2 then ...
}
