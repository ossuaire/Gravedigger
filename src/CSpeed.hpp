#ifndef __CSPEED_H__
#define __CSPEED_H__

#include "CComponent.hpp"

class Character;

class CSpeed : public CComponent {

private:

  float hSpeed;
  float vSpeed;

public:

  CSpeed(Character * _parent,
	 const float _hSpeed=0.0,
	 const float _vSpeed=0.0);
  
  float getHSpeed();
  float getVSpeed();

  void setHSpeed(const float _hSpeed);
  void setVSpeed(const float _vSpeed);

};

#endif
