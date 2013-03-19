#include "ACThrow.hpp"

ACThrow::ACThrow(Character* _parent, GameObject * _item) : ACAction(_parent) {
  x=0;
  y=0;
  item=_item;
}

void ACThrow::setX(const int _x){
  x=_x;
}

void ACThrow::setY(const int _y){
  y=_y;
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
  float hVector = x - position->getX(); // from left      
  float vVector = y - position->getY();
  
  // 80 = radius
  hVector = (hVector/80.0)*(speedItem->getHSpeedMax());
  vVector = (vVector/80.0)*(speedItem->getVSpeedMax());

  // TODO : maxspeed is defined by speed of character also

  CSpeed * speed = (CSpeed*) item->getComponent("Speed");
  speed->setVSpeed(vVector);
  speed->setHSpeed(hVector);

  CState * state = (CState*) item->getComponent("State");
  state->setState("Move");
}
