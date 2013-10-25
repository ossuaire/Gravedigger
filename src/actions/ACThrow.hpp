#ifndef __ACThrow__H__
#define __ACThrow__H__

#include "ACAction.hpp"
#include "CPosition.hpp"
#include "CSpeed.hpp"
#include "CState.hpp"

class GameObject;
class Character;
class ACThrow : public ACAction {

private:
  GameObject* item;

  // position of mouse input
  int x;
  int y;

  float strength; // [0-1]

public:
  ACThrow(Character* _parent, GameObject * item=NULL);
  
  int getX();
  int getY();
  float getStrength();
  GameObject * getItem();

  void setX(const int _x);
  void setY(const int _y);
  void setStrength(const float _strength);
  void setItem(GameObject * _item);

  void execute();
};


#endif
