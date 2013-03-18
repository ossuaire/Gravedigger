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

public:
  ACThrow(Character* _parent, GameObject * item=NULL);
  
  int getX();
  int getY();
  GameObject * getItem();

  void setX(const int _x);
  void setY(const int _y);
  void setItem(GameObject * _item);

  void execute();
};


#endif
