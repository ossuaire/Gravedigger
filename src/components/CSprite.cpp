#include "CSprite.hpp"

CSprite::CSprite(GameObject * parent,
		 const std::string texturePath,
		 const int width,
		 const int height,
		 const float _scale,
		 const bool _isRepeated) : CComponent(parent) {
  texture.create(width,height);
  texture.setRepeated(_isRepeated);
  if (!texture.loadFromFile(texturePath)) {
    std::cout << "Error while loading Sprite, path" + texturePath << std::endl;
  } 
  setScale(_scale);

  sprite.setTexture(texture);
}

sf::Sprite CSprite::getSprite() {
  return sprite;
}

float CSprite::getScale() {
  return scale;
}

void CSprite::setSprite(const std::string texturePath,const sf::IntRect area) {
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
  sprite.setTextureRect(rectangle);
}

void CSprite::setOrigin(const std::string _xOrigin,const std::string _yOrigin){
  if (_xOrigin.compare("left")==0){
    xOrigin = 0.;
  }
  if (_xOrigin.compare("right")==0){
    xOrigin = (sprite.getGlobalBounds().width);
  }
  if (_xOrigin.compare("middle")==0){
    xOrigin = (sprite.getGlobalBounds().width)/(scale*2.0);
  }
  yOrigin=0.;
  //  std::cout << xOrigin << std::endl;
  //TODO ; yorigin ; *scale ???
  sprite.setOrigin(xOrigin,yOrigin);
}
