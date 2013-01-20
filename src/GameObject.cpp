#include "GameObject.hpp"

GameObject::GameObject(const std::string _name) {
  name = _name;
}

CComponent * GameObject::getComponent(const std::string _name) {
  std::map<std::string, CComponent *>::iterator it = components.find(_name);
  if ( it !=  components.end() ) {
    return it->second;
  } else {
    return NULL;
  }
}

void GameObject::addComponent(const std::string _name,
			      CComponent* _component){ 
  components[_name] = _component;
}

void GameObject::delComponent(const std::string _name) {
  std::map<std::string, CComponent *>::iterator it = components.find(_name);
  if ( it != components.end() ) {
    components.erase(it);  
  } // else nothing, considered as delete
}

std::string GameObject::getName() {
  return name;
}
