#ifndef __ATHROW_H__
#define __ATHROW_H__

#include "Character.hpp"
#include "AAnimation.hpp"
#include "CSprite.hpp"
#include "CSpeed.hpp"

class AThrow : public AAnimation {

private:

public:

  AThrow(GameObject * _parent, const sf::Int64 _moduloTime);

  void execute(const sf::Int64 elapsed);
};

#endif
