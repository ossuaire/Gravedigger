#ifndef __ALEFT_H__
#define __ALEFT_H__

#include <SFML/System.hpp>
#include <math.h>
#include "AAnimation.hpp"
#include "CPhysics.hpp"
#include "CAcceleration.hpp"
#include "CSprite.hpp"

class ALeft : public AAnimation {

private:

public:

  ALeft(Character * _parent,const sf::Int64 _moduloTime);

  void execute(const sf::Int64 elapsed);
};

#endif
