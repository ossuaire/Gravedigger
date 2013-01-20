#ifndef __CPOSITION_H__
#define __CPOSITION_H__

#include "CComponent.hpp"
#include "CSprite.hpp"

class GameObject;

class CPosition : public CComponent {

private:

  int x;
  int y;

public:

  CPosition(GameObject * parent,int _x,int _y);

  int getX();
  int getY();

  void setX(int _x);
  void setY(int _y);

};

#endif
