#ifndef __CCOMPONENT_H__
#define __CCOMPONENT_H__

#include "Character.hpp"

class Character;

class CComponent {

private:

public:

  // Abstract class

  CComponent(Character * _parent){parent= _parent;}
  ~CComponent(){}
  
  Character * parent;

};

#endif
