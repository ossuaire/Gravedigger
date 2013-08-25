#include "CharacterFactory.hpp"

#ifndef METERPERPIXEL
#define METERPERPIXEL 0.0210526 // 1.60m / 38*2 pixel (gravedigger sprite)
#endif

CharacterFactory::CharacterFactory(b2World * _world) {
  world = _world;
}

/**
 ** Names must be set as it were class Name
 **/
Character * CharacterFactory::get(const std::string name) {
  ItemFactory iF;
  Character * character;

  // Definition of people body
  b2BodyDef characterBodyDef;
  characterBodyDef.type = b2_dynamicBody;
  characterBodyDef.position.Set(0,0);
  characterBodyDef.angle = 0;

  if (name.compare("Gravedigger")==0) { // Instance of Gravedigger required
    character = new Character(std::string("Gravedigger"));

    // creating physics
    characterBodyDef.position.Set(100*METERPERPIXEL, 240*METERPERPIXEL);
    characterBodyDef.fixedRotation = true;
    b2Body * gravediggerBody = world->CreateBody(&characterBodyDef);
    b2PolygonShape boxShape;
    boxShape.SetAsBox(100*METERPERPIXEL,100*METERPERPIXEL);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = .5;
    boxFixtureDef.friction = 0.9;
    gravediggerBody->CreateFixture(&boxFixtureDef);

    CComponent * physics = new CPhysics(character,gravediggerBody);
    CComponent * sprite =
      new CSprite(character,
		  std::string("../material/img/chara-design/butcher.png"),
		  2.0);
    ((CSprite *) sprite)->setOrigin("middle","middle");
    //    sf::Time oneSec = sf::seconds(1.0)
    sf::Int64 thousandMillisec = sf::seconds(1.0).asMicroseconds(); 

    CComponent * acceleration = new CAcceleration(character,
						  2.0*thousandMillisec);
    character->addComponent("Physics",physics);
    character->addComponent("Sprite",sprite);
    character->addComponent("Acceleration",acceleration);

    // Creating actions
    GameObject * shovel = iF.get("Shovel");
    ACAction * throwAction = new ACThrow(character,shovel);
    character->addComponent("Throw",(CComponent*)throwAction);
    
    // Creating states
    CState * state = new CState(character);
    AStand * stand = new AStand(character, 2.0*thousandMillisec);
    sf::IntRect subSprite1(0,0,100,100); // Stand 1
    sf::IntRect subSprite2(0,0,100,100); // Stand 2
    stand->addSubSprite(subSprite1);
    stand->addSubSprite(subSprite2);
    ALeft  * left  = new ALeft (character, 0.6*thousandMillisec);
    ARight * right = new ARight(character, 0.6*thousandMillisec);
    sf::IntRect subSprite3(100,0,100,100);
    sf::IntRect subSprite4(200,0,100,100);
    sf::IntRect subSprite5(300,0,100,100);
    left->addSubSprite(subSprite5);
    left->addSubSprite(subSprite4);
    left->addSubSprite(subSprite3);
    left->addSubSprite(subSprite4);
    right->addSubSprite(subSprite5);
    right->addSubSprite(subSprite4);
    right->addSubSprite(subSprite3);
    right->addSubSprite(subSprite4);
    state->addAnimation(std::string("Stand"),stand);
    state->addAnimation(std::string("Left"),  left);
    state->addAnimation(std::string("Right"),right);
    
    character->addComponent(std::string("State"),state);
    state->setState("Stand");
  }
  
  return character;

}
