#ifndef __ALEFT_H__
#define __ALEFT_H__

#include <SFML/System.hpp>
#include "AAnimation.hpp"
#include "CPosition.hpp"
#include "CSpeed.hpp"
#include "CAcceleration.hpp"

class ALeft : public AAnimation {

private:

public:

  ALeft(Character * _parent,const sf::Int32 _moduloTime);

  void update(const sf::Int32 elapsed);
};

#endif
