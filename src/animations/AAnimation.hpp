#ifndef __AANIMATION_H__
#define __AANIMATION_H__

#include "Character.hpp"
#include <SFML/System.hpp>
class AAnimation {

private:

  sf::Int32 moduloTime;

public:

  Character* parent;

  AAnimation(Character* _parent, const sf::Int32 _moduloTime);
  ~AAnimation();

  sf::Int32 getModuloTime();

  void setModuloTime(const sf::Int32 _moduloTime);

  virtual void execute(sf::Int32 elapsed)=0;

};

#endif
