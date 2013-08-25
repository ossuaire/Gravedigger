#include "AThrow.hpp"

AThrow::AThrow(GameObject * _parent,
	       const sf::Int64 _moduloTime) : AAnimation(_parent,_moduloTime) {
}

void AThrow::execute(const sf::Int64 elapsed) {
  sf::Int64 tempElapsedSum = getElapsedSum() + elapsed;

  CSpeed * speed = (CSpeed*) parent->getComponent("Speed");
  CSprite * sprite = (CSprite*) parent->getComponent("Sprite");

}
