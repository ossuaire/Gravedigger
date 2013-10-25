#include "CState.hpp"


CState::CState(GameObject* _parent): CComponent(_parent) {
}

std::string CState::getState() {
  return state;
}

void CState::setState(const std::string _state) {
  state = _state;
  AAnimation * animation = getAnimation(state);
  animation->setElapsedSum(sf::Int64(0));
}

AAnimation * CState::getAnimation(const std::string name) {
  std::map<std::string, AAnimation *>::iterator it;
  it = animations.find(name);
  if ( it !=  animations.end() ) {
    return it->second;
  } else {
    return NULL;
  }
}

void CState::delAnimation(const std::string name) {
  std::map<std::string, AAnimation *>::iterator it = animations.find(name);
  if ( it != animations.end() ) {
    animations.erase(it);
  } // else nothing, considered as delete                             
}

void CState::addAnimation(const std::string name, AAnimation * animation) {
  animations[name] = animation;
}

void CState::update(sf::Int64 elapsed) {
  // increment time, call the current state
  getAnimation(getState())->execute(elapsed);
}
