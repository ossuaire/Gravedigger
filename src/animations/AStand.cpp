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
  sf::Int64 temp = 0;
  int k = 0; //index to read in tab
  while (temp < tempElapsedSum) {
    ++k;
    temp = temp + (getModuloTime()/getSubSprites().size());
  }
  if ((k-1)>=getSubSprites().size())
    {k=getSubSprites().size();}
  sprite->updateSubSprite(getSubSprites().at(k-1));

  sprite->setOrigin("middle","middle");
  setElapsedSum(tempElapsedSum%getModuloTime());
}
