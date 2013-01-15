#include "CharacterFactory.hpp"

CharacterFactory::CharacterFactory() {
  // Nothing yet
}

/**
 ** Names must be set as it were class Name
 **/
Character * CharacterFactory::get(const std::string name) {
  Character * character;

  if (name.compare("Gravedigger")==0) { // Instance of Gravedigger required
    character = new Character(std::string("Gravedigger"));
    CComponent * position = new CPosition(character,100,100);
    CComponent * sprite =
      new CSprite(character,
		  std::string("material/img/chara-design/gravedigger.png"),
		  2.0);
    ((CSprite *) sprite)->updateSubSprite(18,14,21,19); // TODO: Rework on it
    CComponent * speed = new CSpeed(character);
    character->addComponent(std::string("Position"),position);
    character->addComponent(std::string("Sprite"),sprite);
    character->addComponent(std::string("Speed"),speed);
  }
  
  return character;

}
