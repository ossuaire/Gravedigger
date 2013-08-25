#ifndef __ENVIRONMENTFACTORY_H__
#define __ENVIRONMENTFACTORY_H__

#include <Box2D/Box2D.h>
#include <string>
#include "Environment.hpp"
#include "CPhysics.hpp"
#include "CSprite.hpp"

class EnvironmentFactory {

private:
  
  b2World * world;
  
public:

  EnvironmentFactory(b2World * _world);
  Environment * get(const std::string name);

};

#endif
