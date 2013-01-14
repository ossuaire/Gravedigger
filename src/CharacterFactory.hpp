#ifndef __CHARACTERFACTORY_H__
#define __CHARACTERFACTORY_H__

#include <iostream>
#include <string>
#include "Character.hpp"
#include "CPosition.hpp"
#include "CSprite.hpp"
#include "CSpeed.hpp"

/**
 ** Factory which initialize a character and all its components.
 **/
class CharacterFactory {

private:

public:

  CharacterFactory();

  Character* get(const std::string name);

};


#endif
