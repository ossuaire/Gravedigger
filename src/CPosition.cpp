#include "CPosition.hpp"

CPosition::CPosition(int _x, int _y) {
  setX(_x);
  setY(_y);
}


int CPosition::getX() {
  return x;
}

int CPosition::getY() {
  return y;
}

void CPosition::setX(int _x) {
  x = _x;
}

void CPosition::setY(int _y) {
  y = _y;
}
