#ifndef __CACCELERATION_H__
#define __CACCELERATION_H__

#include "CComponent.hpp"

class Character;

class CAcceleration : public CComponent {

private:

  // Acceleration value at a given time
  float vAcceleration;
  float hAcceleration;

  // Value added or subbed at each call
  float vAccInc;
  float hAccInc;

  // Maximum acceleration value
  float vAccMax;
  float hAccMax;

public:

  CAcceleration(Character* _parent,
		const float _hAcceleration=0.0,
		const float _vAcceleration=0.0,
		const float _hAccInc=0.1,
		const float _vAccInc=0.1,
		const float _hAccMax=10.0,
		const float _vAccMax=15.0);

  float getVAcceleration();
  float getHAcceleration();
  float getVAccInc();
  float getHAccInc();
  float getVAccMax();
  float getHAccMax();


  void setVAcceleration(const float _vAcceleration);
  void setHAcceleration(const float _hAcceleration);
  void setVAccInc(const float _vAccInc);
  void setHAccInc(const float _hAccInc);
  void setVAccMax(const float _vAccMax);
  void setHAccMax(const float _hAccMax);

};

#endif
