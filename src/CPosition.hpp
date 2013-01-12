#ifndef __CPOSITION_H__
#define __CPOSITION_H__

#include "CComponent.hpp"

class CPosition : public CComponent {

private:

  int x;
  int y;

public:

  CPosition(int _x,int _y);

  int getX();
  int getY();

  void setX(int _x);
  void setY(int _y);

};

#endif
