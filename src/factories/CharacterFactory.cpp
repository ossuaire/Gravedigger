#include "CharacterFactory.hpp"

CharacterFactory::CharacterFactory() {
  // Nothing yet
}

/**
 ** Names must be set as it were class Name
 **/
Character * CharacterFactory::get(const std::string name) {
  ItemFactory iF;
  Character * character;

  if (name.compare("Gravedigger")==0) { // Instance of Gravedigger required
    character = new Character(std::string("Gravedigger"));
    CComponent * position = new CPosition(character,100,240);
    CComponent * boundingbox = new CBoundingBox(character,
						sf::IntRect(100,240,42,38));
    CComponent * sprite =
      new CSprite(character,
		  std::string("material/img/chara-design/gravedigger.png"),
		  1.0);
    //((CSprite *) sprite)->updateSubSprite(3,3,42,38); // TODO: Rework on it
    //    ((CSprite *) sprite)->setOrigin("middle","bottom");
    sf::Time oneSec = sf::seconds(1.0);
    sf::Int64 thousandMillisec = oneSec.asMicroseconds(); 

    CComponent * speed = new CSpeed(character);
    CComponent * acceleration = new CAcceleration(character,
						  2.0*thousandMillisec);
    character->addComponent("Position",position);
    character->addComponent("BoundingBox",boundingbox);
    character->addComponent("Sprite",sprite);
    character->addComponent("Speed",speed);
    character->addComponent("Acceleration",acceleration);

    // Creating actions
    GameObject * shovel = iF.get("Shovel");
    ACAction * throwAction = new ACThrow(character,shovel);
    character->addComponent("Throw",(CComponent*)throwAction);
    
    // Creating states
    CState * state = new CState(character);
    AStand * stand = new AStand(character, 2.0*thousandMillisec);
    sf::IntRect subSprite1(2,3,45,44); // Stand 1
    sf::IntRect subSprite2(52,3,45,44); // Stand 2
    stand->addSubSprite(subSprite1);
    stand->addSubSprite(subSprite2);
    ALeft  * left  = new ALeft (character, 0.35*thousandMillisec);
    ARight * right = new ARight(character, 0.35*thousandMillisec);
    sf::IntRect subSprite3(2,53,46,44);
    sf::IntRect subSprite4(52,53,46,44);
    sf::IntRect subSprite5(102,53,46,44);
    left->addSubSprite(subSprite3);
    left->addSubSprite(subSprite4);
    left->addSubSprite(subSprite5);
    right->addSubSprite(subSprite3);
    right->addSubSprite(subSprite4);
    right->addSubSprite(subSprite5);
    state->addAnimation(std::string("Stand"),stand);
    state->addAnimation(std::string("Left"),  left);
    state->addAnimation(std::string("Right"),right);
    
    character->addComponent(std::string("State"),state);
    state->setState("Stand");
  }
  
  return character;

}
