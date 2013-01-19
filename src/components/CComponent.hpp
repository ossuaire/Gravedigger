#ifndef __CCOMPONENT_H__
#define __CCOMPONENT_H__

#include "Character.hpp"

class Character;

class CComponent {

private:

public:

  CComponent(Character * _parent);
  ~CComponent();
  
  Character * parent;

};

#endif
