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
    CComponent * position = new CPosition(character,100,200);
    CComponent * sprite =
      new CSprite(character,
		  std::string("material/img/chara-design/gravedigger.png"),
		  sf::IntRect(0,0,21,19),
		  2.0);
    ((CSprite *) sprite)->updateSubSprite(18,14,21,19); // TODO: Rework on it
    CComponent * speed = new CSpeed(character);
    CComponent * acceleration = new CAcceleration(character);
    character->addComponent(std::string("Position"),position);
    character->addComponent(std::string("Sprite"),sprite);
    character->addComponent(std::string("Speed"),speed);
    character->addComponent(std::string("Acceleration"),acceleration);
    
    // Creating states
    sf::Time oneSec = sf::seconds(1.0);
    sf::Int32 thousandMillisec = oneSec.asMilliseconds(); 
    CState * state = new CState(character, thousandMillisec);
    AStand * stand = new AStand(character, thousandMillisec);
    ALeft  * left  = new ALeft (character, thousandMillisec);
    ARight * right = new ARight(character, thousandMillisec);
    state->addAnimation(std::string("Stand"),stand);
    state->addAnimation(std::string("Left"),  left);
    state->addAnimation(std::string("Right"),right);
    
    character->addComponent(std::string("State"),state);
    state->setState("Stand");
  }
  
  return character;

}
