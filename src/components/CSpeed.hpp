#ifndef __CSPEED_H__
#define __CSPEED_H__

#include <algorithm>
#include "CComponent.hpp"

class GameObject;

class CSpeed : public CComponent {

private:

  // Speed at a given time
  float hSpeed;
  float vSpeed;

  // Max value for each speed
  float hSpeedMax;
  float vSpeedMax;

public:

  CSpeed(GameObject * _parent,
	 const float _hSpeed=0.0,
	 const float _vSpeed=0.0,
	 const float _hSpeedMax=10.0,
	 const float _vSpeedMax=15.0); // Moar cuz of fallin'
  
  float getHSpeed();
  float getVSpeed();
  float getHSpeedMax();
  float getVSpeedMax();

  void setHSpeed(const float _hSpeed);
  void setVSpeed(const float _vSpeed);
  void setHSpeedMax(const float _hSpeedMax);
  void setVSpeedMax(const float _vSpeedMax);


};

#endif
