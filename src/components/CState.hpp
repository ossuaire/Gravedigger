#ifndef __CSTATE_H__
#define __CSTATE_H__

#include "CComponent.hpp"
#include "AAnimation.hpp"
#include <string>
#include <map>

class GameObject;

class CState: public CComponent {

private:

  std::map<std::string, AAnimation*> animations;

  std::string state;

public:

  CState(GameObject* parent);

  std::string getState();
  sf::Int64 getElapsedSum();
  sf::Int64 getModuloTime();
  AAnimation * getAnimation(const std::string  name);

  void setState(const std::string _state);
  void setModuloTime(const sf::Int64 _moduloTime);
  void addAnimation(const std::string name, AAnimation * animation);
  void delAnimation(const std::string  name);

  void update(sf::Int64 elapsed);
};


#endif
