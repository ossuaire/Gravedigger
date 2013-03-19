#ifndef __ITEMFACTORY_H__
#define __ITEMFACTORY_H__

#include <string>
#include "Item.hpp"
#include "CPosition.hpp"
#include "CSprite.hpp"
#include "CState.hpp"
#include "CSpeed.hpp"
#include "CAcceleration.hpp"
#include "AThrow.hpp"

class ItemFactory {

private:

public:

  ItemFactory();
  Item * get(const std::string name);

};

#endif
