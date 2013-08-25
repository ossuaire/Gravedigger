#include "AStand.hpp"

AStand::AStand(Character * _parent,
	       const sf::Int64 _moduloTime) : AAnimation(_parent,_moduloTime) {
}

void AStand::execute(const sf::Int64 elapsed) {
  // TODO: Verif' they are existing components
  // #1 get all components
  sf::Int64 tempElapsedSum = getElapsedSum() + elapsed;
  CSprite * sprite = (CSprite *) parent->getComponent("Sprite");
  sprite->updatePosition();

  // #3 change sprites
  // For now, only 2 sprites allowed, maybe tochange in future
  if (tempElapsedSum < getModuloTime()/2){
    sprite->updateSubSprite(getSubSprites().at(0));
  } else {
    if (getSubSprites().size()>1) {
      sprite->updateSubSprite(getSubSprites().at(1));
    }
  }
  sprite->setOrigin("middle","middle");
  setElapsedSum(tempElapsedSum%getModuloTime());
}
