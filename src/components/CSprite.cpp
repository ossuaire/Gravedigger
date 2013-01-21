#include "CSprite.hpp"

CSprite::CSprite(GameObject * parent,
		 const std::string texturePath,
		 const float _scale,
		 const float _angle) : CComponent(parent) {
  if (!texture.loadFromFile(texturePath)) {
    std::cout << "Error while loading Sprite, path" + texturePath << std::endl;
  } 

  setScale(_scale);

  sprite.setTexture(texture);
  sprite.setScale(_scale,_scale); // Square
}

sf::Sprite CSprite::getSprite() {
  return sprite;
}

float CSprite::getScale() {
  return scale;
}

void CSprite::setSprite(const std::string texturePath) {
  if (!texture.loadFromFile(texturePath)) {
    std::cout << "Error while loading Sprite, path" + texturePath << std::endl;
  } 

  sprite.setTexture(texture);
}

void CSprite::setScale(const float _scale) {
  scale = _scale;
  sprite.setScale(_scale,_scale);
}

void CSprite::setDirection(const std::string direction) {
  if (direction.compare("left")==0) {
      sprite.setScale(-scale,scale);    
  }
  if (direction.compare("right")==0) {
    sprite.setScale(scale,scale);
  }
}

// Call diz function implies an existing CPosition component
void CSprite::updatePosition() {
  CPosition * position =(CPosition *) parent->getComponent("Position");
  sprite.setPosition( position->getX() , position->getY());
}

void CSprite::updateSubSprite(const int left,
			     const int top,
			     const int width,
			     const int height) {
  sf::IntRect rectangle(left,top,width,height);
  boundingBox = rectangle;
  sprite.setTextureRect(rectangle);
  sprite.setOrigin(width/2,top);
}
