#ifndef __CSTATE_H__
#define __CSTATE_H__

#include "CComponent.hpp"

class Character;

class CState: public CComponent {

private:

  // List of states possible
  // List of state=>animation???
  // animation = list of sprite and condition on it?

  // counter ?
  // +framerate?

public:

  CState(Character* parent);

  //setState

  //getState

  //update();
};


#endif
