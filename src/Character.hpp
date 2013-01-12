#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <iostream>
#include <string>
#include <map>
#include "CComponent.hpp"

class Character {

private:

  std::string name; // Name of this character instance
  std::map<std::string, CComponent*> components;


public:

  Character(const std::string _name);

  CComponent * getComponent(const std::string _name);
  void addComponent(const std::string _name, CComponent* _component);
  void delComponent(const std::string _name);

  std::string getName();
};

#endif
