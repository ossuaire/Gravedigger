#ifndef __CHARACTERFACTORY_H__
#define __CHARACTERFACTORY_H__

#include <SFML/System.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include <string>

#include "ItemFactory.hpp"

#include "Character.hpp"
#include "CPhysics.hpp"
#include "CPosition.hpp"
#include "CSprite.hpp"
#include "CSpeed.hpp"
#include "CAcceleration.hpp"
#include "CState.hpp"

#include "AAnimation.hpp"
#include "AStand.hpp" 
#include "ALeft.hpp"
#include "ARight.hpp"

#include "ACThrow.hpp"

/**
 ** Factory which initialize a character and all its components.
 **/
class CharacterFactory {

private:

  b2World * world;

public:

  CharacterFactory(b2World * _world);

  Character* get(const std::string name);

};

#endif
