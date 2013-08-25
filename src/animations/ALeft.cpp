#include "ALeft.hpp"

ALeft::ALeft(Character * _parent,
	     const sf::Int64 _moduloTime) : AAnimation(_parent,_moduloTime) {
}

void ALeft::execute(const sf::Int64 elapsed) {
  // TODO: Verif' they are existing components
  // #1 get all components
  sf::Int64 tempElapsedSum = getElapsedSum() + elapsed;

  CAcceleration * acceleration;
  acceleration = (CAcceleration *) parent->getComponent("Acceleration");
  CSprite * sprite = (CSprite *) parent->getComponent("Sprite");
  
  CPhysics * physics = (CPhysics *) parent->getComponent("Physics");
  (physics->getBody())->ApplyLinearImpulse(b2Vec2(-3,0),
				      (physics->getBody())->GetWorldCenter());
  //  (physics->getBody())->ApplyForce( b2Vec2(-50,0),
  //				    (physics->getBody())->GetWorldCenter());
  sprite->updatePosition();

  // #3 change sprites
  sf::Int64 temp = 0;
  int k = 0; //index to read in tab  
  while (temp < tempElapsedSum) {
    ++k;
    temp = temp + getModuloTime()/getSubSprites().size();
  }
  if ((k-1)>=getSubSprites().size())
    { k=getSubSprites().size(); }
  sprite->updateSubSprite(getSubSprites().at(k-1));
  sprite->setDirection("left");
  setElapsedSum(tempElapsedSum%getModuloTime());
}
