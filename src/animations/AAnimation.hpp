#ifndef __AANIMATION_H__
#define __AANIMATION_H__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Character.hpp"

class AAnimation {

private:

  sf::Int64 moduloTime;
  std::vector<sf::IntRect> subSprites;

public:

  Character* parent;

  AAnimation(Character* _parent, const sf::Int64 _moduloTime);
  ~AAnimation();

  sf::Int64 getModuloTime();

  void setModuloTime(const sf::Int64 _moduloTime);
  void addSubSprite(const sf::IntRect subSprite);
  std::vector<sf::IntRect> getSubSprites();

  // Function processing all callz of updating
  virtual void execute(const sf::Int64 elapsed)=0;

};

#endif
