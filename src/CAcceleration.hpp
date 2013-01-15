#ifndef __CACCELERATION_H__
#define __CACCELERATION_H__

#include "CComponent.hpp"

class Character;

class CAcceleration : public CComponent {

private:

  // Acceleration value added or subbed to speed
  float vAcceleration;
  float hAcceleration;

public:

  CAcceleration(Character* _parent,
		const float _hAcceleration=0.1,
		const float _vAcceleration=0.1);

  float getVAcceleration();
  float getHAcceleration();
  
  void setVAcceleration(const float _vAcceleration);
  void setHAcceleration(const float _hAcceleration);

};

#endif
