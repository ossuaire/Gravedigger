#ifndef __CBOUNDINGBOX_H__
#define __CBOUNDINGBOX_H__

#include <SFML/Graphics.hpp>
#include "CComponent.hpp"

class GameObject;

class CBoundingBox : public CComponent {

private:

  sf::IntRect boundingBox;

public:

  CBoundingBox(GameObject * _parent, sf::IntRect _boundingBox);

  sf::IntRect getBoundingBox();

  void setBoundingBox(const sf::IntRect _boundingBox);

};

#endif
