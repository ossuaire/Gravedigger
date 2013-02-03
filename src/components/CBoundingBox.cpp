#include "CBoundingBox.hpp"

CBoundingBox::CBoundingBox(GameObject * _parent,
			   sf::IntRect _boundingBox): CComponent(_parent) {
  boundingBox = _boundingBox;
}

sf::IntRect CBoundingBox::getBoundingBox(){
  return boundingBox;
}

void CBoundingBox::setBoundingBox(const sf::IntRect _boundingBox){
  boundingBox = _boundingBox;
}
