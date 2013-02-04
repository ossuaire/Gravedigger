#ifndef __ARIGHT_H__
#define __ARIGHT_H__

#include <SFML/System.hpp>
#include <math.h>
#include "AAnimation.hpp"
#include "CPosition.hpp"
#include "CSpeed.hpp"
#include "CAcceleration.hpp"
#include "CSprite.hpp"

class ARight : public AAnimation {

private:

public:

  ARight(Character * _parent,const sf::Int32 _moduloTime);

  void execute(const sf::Int32 elapsed);
};

#endif
