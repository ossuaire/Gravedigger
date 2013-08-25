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
  
}
