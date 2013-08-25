#include "CSprite.hpp"

#ifndef PIXELPERMETER
#define PIXELPERMETER 47.5
#endif

CSprite::CSprite(GameObject * parent,
		 const std::string texturePath,
		 const float _scale,
		 const bool _isRepeated) : CComponent(parent) {
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
      setOrigin("middle","middle");
  }
  if (direction.compare("right")==0) {
    sprite.setScale(scale,scale);
    setOrigin("middle","middle");
  }
}

// Call diz function implies an existing CPosition component
void CSprite::updatePosition() {
  b2Body * body = ((CPhysics *) parent->getComponent("Physics"))->getBody();
  sprite.setPosition(((body->GetPosition()).x)*PIXELPERMETER,
		     ((body->GetPosition()).y)*PIXELPERMETER);
}

void CSprite::updateSubSprite(const int left,
			      const int top,
			      const int width,
			      const int height) {
  sf::IntRect rectangle(left,top,width,height);
  sprite.setTextureRect(rectangle);
}

void CSprite::updateSubSprite(const sf::IntRect subSprite) {
  sprite.setTextureRect(subSprite);
}

void CSprite::setOrigin(const std::string _xOrigin,const std::string _yOrigin){
  // default set to left, top
  
  if (_xOrigin.compare("right")==0){
    xOrigin = (sprite.getLocalBounds().width);
  } else {
    if (_xOrigin.compare("middle")==0){
      xOrigin = (sprite.getLocalBounds().width)/2.0;
    }}
  if (_yOrigin.compare("bottom")==0){
    yOrigin = (sprite.getLocalBounds().height);
  } else {
    if (_yOrigin.compare("middle")==0){
      yOrigin = (sprite.getLocalBounds().height)/2.0;
    }}

  sprite.setOrigin(xOrigin,yOrigin);
}
