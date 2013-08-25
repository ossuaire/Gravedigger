#ifndef __CSPRITE_H__
#define __CSPRITE_H__

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <string>
#include <iostream>
#include "CComponent.hpp"
#include "CPhysics.hpp"
#include "CPosition.hpp"

class GameObject;

class CSprite : public CComponent {

private:

  sf::Sprite sprite;
  sf::Texture texture;

  float scale;
  // coordinate of the origin of transformations
  float xOrigin;
  float yOrigin;

public:
  
  CSprite(GameObject * parent,
	  const std::string texturePath,
	  const float _scale=1.0,
	  const bool _isRepeated=false);
  
  sf::Sprite getSprite();
  float getScale();

  void setSprite(const std::string texturePath,const sf::IntRect area);
  void setScale(const float _scale);
  void setDirection(const std::string direction);
  void setOrigin(const std::string _xOrigin, const std::string _yOrigin);

  void updatePosition();

  void updateSubSprite(const int left,
		       const int top,
		       const int width,
		       const int height);

  void updateSubSprite(const sf::IntRect subSprite);
};

#endif
