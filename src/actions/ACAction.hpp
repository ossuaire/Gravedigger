#ifndef __ACAction_H__
#define __ACAction_H__

#include "CComponent.hpp"

class Character;

class ACAction : public CComponent {

private:

public:

  ACAction(Character* _parent);

  // TODO on each ... Maybe add precondition ? 
  virtual void execute() = 0;
};

#endif
