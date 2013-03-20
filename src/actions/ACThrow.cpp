#include "ACThrow.hpp"

ACThrow::ACThrow(Character* _parent, GameObject * _item) : ACAction(_parent) {
  x=0;
  y=0;
  strength=0.f;
  item=_item;
}

void ACThrow::setX(const int _x){
  x=_x;
}

void ACThrow::setY(const int _y){
  y=_y;
}

void ACThrow::setStrength(const float _strength){
  strength=_strength;
}

void ACThrow::setItem(GameObject * _item){
  item = _item;
}

GameObject * ACThrow::getItem(){
  return item;
}

int ACThrow::getX(){
  return x;
}

int ACThrow::getY(){
  return y;
}

float ACThrow::getStrength(){
  return strength;
}

void ACThrow::execute() {

  // #1 TODO Verify preconditions
  
  // #2 re init the values
  CPosition * position=(CPosition*)parent->getComponent("Position");
  CPosition * positionItem=(CPosition*)item->getComponent("Position");
  CSpeed * speedItem = (CSpeed*)item->getComponent("Speed");
  positionItem->setX(position->getX());
  positionItem->setY(position->getY());

  // TODO: radius of throw
  // Maxspeed when radius > input
  int hVector = x - position->getX(); // from left      
  int vVector = y - position->getY();

  int max = std::max(std::abs(hVector),std::abs(vVector));
  float hVectorU = (float) hVector/max;
  float vVectorU = (float) vVector/max;


  float hVectorF = (hVectorU*strength)*(speedItem->getHSpeedMax());
  float vVectorF = (vVectorU*strength)*(speedItem->getVSpeedMax());

  // TODO : maxspeed is defined by speed of character also

  CSpeed * speed = (CSpeed*) item->getComponent("Speed");
  speed->setVSpeed(vVectorF);
  speed->setHSpeed(hVectorF);

  CState * state = (CState*) item->getComponent("State");
  state->setState("Move");
}
