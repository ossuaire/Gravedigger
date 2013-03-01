#ifndef __CACCELERATION_H__
#define __CACCELERATION_H__

#include <SFML/System.hpp>
#include "CComponent.hpp"

class GameObject;

class CAcceleration : public CComponent {

private:

  // Time in microseconds to reach max speed
  sf::Int64 vAcceleration;
  sf::Int64 hAcceleration;

public:

  CAcceleration(GameObject* _parent,
		const sf::Int64 _hAcceleration=1000000, // 1s
		const sf::Int64 _vAcceleration=1000000); // 1s

  sf::Int64 getVAcceleration();
  sf::Int64 getHAcceleration();
  
  void setVAcceleration(const sf::Int64 _vAcceleration);
  void setHAcceleration(const sf::Int64 _hAcceleration);

};

#endif
