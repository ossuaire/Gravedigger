#ifndef __CSTATE_H__
#define __CSTATE_H__

#include "CComponent.hpp"
#include "AAnimation.hpp"
#include <string>
#include <map>

class Character;

class CState: public CComponent {

private:

  std::map<std::string, AAnimation*> animations;

  std::string state;
  
  sf::Int32 elapsedSum; // unit: ms
  sf::Int32 moduloTime; // unit: ms
  
  void setElapsedSum(const sf::Int32 _elapsedSum);

public:

  CState(Character* parent,const sf::Int32 _moduloTime);

  std::string getState();
  sf::Int32 getElapsedSum();
  sf::Int32 getModuloTime();
  AAnimation * getAAnimation(const std::string  name);

  void setState(const std::string _state);
  void setModuloTime(const sf::Int32 _moduloTime);
  void addAAnimation(AAnimation * animation);
  void delAAnimation(const std::string  name);

  void update(sf::Int32 elapsed);
};


#endif
