#ifndef __ASTAND_H__
#define __ASTAND_H__

#include <SFML/System.hpp>
#include <algorithm>
#include <cmath>
#include "AAnimation.hpp"
#include "CPosition.hpp"
#include "CSpeed.hpp"
#include "CAcceleration.hpp"
#include "CSprite.hpp"

class AStand : public AAnimation {

private:

public:

  AStand(Character * _parent,const sf::Int64 _moduloTime);

  void execute(const sf::Int64 elapsed);
};

#endif
