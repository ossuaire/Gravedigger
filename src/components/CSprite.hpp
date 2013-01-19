#ifndef __CSPRITE_H__
#define __CSPRITE_H__

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "CComponent.hpp"
#include "CPosition.hpp"

class Character;

class CSprite : public CComponent {

private:

  sf::Sprite sprite;
  sf::Texture texture;

  float scale;

public:
  
  CSprite(Character * parent,
	  const std::string texturePath,
	  const float _scale=1.0,
	  const float _angle=0.0); // left by default
  
  sf::Sprite getSprite();
  float getScale();

  void setSprite(const std::string texturePath);
  void setScale(const float _scale);
  void setDirection(const std::string direction);

  void updatePosition();

  void updateSubSprite(const int left,
		       const int top,
		       const int width,
		       const int height);

};

#endif
