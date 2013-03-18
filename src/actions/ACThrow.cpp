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
  positionItem->setX(position->getX());
  positionItem->setY(position->getY());

  int hVector = x - position->getX(); // from left      
  int vVector = y - position->getY();

  CSpeed * speed = (CSpeed*) item->getComponent("Speed");
  speed->setVSpeed(vVector);
  speed->setHSpeed(hVector);

  CState * state = (CState*) item->getComponent("State");
  state->setState("Move");
}
