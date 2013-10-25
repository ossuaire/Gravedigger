#ifndef __CCOMPONENT_H__
#define __CCOMPONENT_H__

#include "GameObject.hpp"

class GameObject;

class CComponent {

private:

public:

  CComponent(GameObject * _parent);
  ~CComponent();
  
  GameObject * parent;

};

#endif
