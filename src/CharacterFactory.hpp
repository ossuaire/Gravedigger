#ifndef __CHARACTERFACTORY_H__
#define __CHARACTERFACTORY_H__

#include <string>
#include "Character.hpp"
#include "CPosition.hpp"
#include <iostream>

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
