#ifndef __CPHYSICS_H__
#define __CPHYSICS_H__

#include <Box2D/Box2D.h>
#include "CComponent.hpp"


class GameObject;

class CPhysics : public CComponent {

private:

  b2Body* body;

public:
  
  CPhysics(GameObject* parent, b2Body * _body);

  void setBody(b2Body * _body);
  b2Body * getBody();

};


#endif
