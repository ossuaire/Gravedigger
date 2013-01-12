#include "Character.hpp"

Character::Character(const std::string _name) {
  name = _name;
}

CComponent * Character::getComponent(const std::string _name) {
  return components.at(_name);
}

void Character::addComponent(const std::string _name, CComponent* _component){ 
  components[_name] = _component;
}

void Character::delComponent(const std::string _name) {
  components.erase(_name);
}

std::string Character::getName() {
  return name;
}
