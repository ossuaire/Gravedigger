#ifndef __AANIMATION_H__
#define __AANIMATION_H__

#include <SFML/System.hpp>
#include "Character.hpp"

class AAnimation {

private:

  sf::Int32 moduloTime;

public:

  Character* parent;

  AAnimation(Character* _parent, const sf::Int32 _moduloTime);
  ~AAnimation();

  sf::Int32 getModuloTime();

  void setModuloTime(const sf::Int32 _moduloTime);

  // Function processing all callz of updating
  virtual void execute(const sf::Int32 elapsed)=0;

};

#endif
