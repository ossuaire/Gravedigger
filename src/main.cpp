#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CharacterFactory.hpp"
#include "EnvironmentFactory.hpp"

using namespace std;

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Gravedigger");
  window.setFramerateLimit(60);

  CharacterFactory cf;
  Character * pelle = NULL;
  Character * gravedigger = cf.get("Gravedigger");
  CSprite * sprite = (CSprite *) gravedigger->getComponent("Sprite");
  CState * state = (CState*) gravedigger->getComponent("State");
  sprite->updatePosition();

  EnvironmentFactory ef;
  Environment * floor = ef.get("Floor");
  CSprite * fsprite = (CSprite *) floor->getComponent("Sprite");
  fsprite->updatePosition();
  sf::Clock clock;
  while (window.isOpen()) {
    sf::Event event;
    sf::Time elapsed = clock.restart();

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
	window.close();
      }
      if ((event.type == sf::Event::KeyPressed) &&
	  (event.key.code == sf::Keyboard::D) &&
	  (state->getState().compare("Right")!=0)) {
	state->setState("Right");
      }
      if ((event.type == sf::Event::KeyPressed) &&
	  (event.key.code == sf::Keyboard::Q) &&
	  (state->getState().compare("Left")!=0)) {
	state->setState("Left");
      }
      if ((event.type == sf::Event::KeyReleased) &&
	  (event.key.code == sf::Keyboard::D) &&
	  (state->getState().compare("Right")==0)) {
	state->setState("Stand");
      }
      if ((event.type == sf::Event::KeyReleased) &&
	  (event.key.code == sf::Keyboard::Q) &&
	  (state->getState().compare("Left")==0)) {
	state->setState("Stand");
      }
      if (event.type == sf::Event::MouseButtonPressed) {
	// Do an action
	//std::cout << event.mouseButton.x << std::endl;
	//std::cout << event.mouseButton.y << std::endl;
	// process vector
	pelle = new Character("Pelle");
	CPosition * position=(CPosition*)gravedigger->getComponent("Position");
	int hVector = event.mouseButton.x - position->getX(); // from left
	int vVector = position->getY() - event.mouseButton.y; // cuz from top
	CComponent * position2 = new CPosition(pelle,
					       position->getX(),
					       position->getY());
	CComponent * sprite2;
	sf::Int64 microsec = sf::seconds(1.0).asMicroseconds();
	sprite2 = new CSprite(pelle,
			      "material/img/chara-design/zelda-heart.png",
			      5.0);
	CComponent * speed2 = new CSpeed(pelle,5.0,5.0,20.0,20.0);
	CComponent * accel2 = new CAcceleration(pelle, microsec);
	pelle->addComponent("Position",position2);
	pelle->addComponent("Sprite",sprite2);
	pelle->addComponent("Speed",speed2);
	pelle->addComponent("Acceleration",accel2);
	CComponent * state2 = new CState(pelle);
	sf::IntRect subsprite(0,0,9,9);
	if ( hVector<0) {
	  AAnimation * move = new ALeft(pelle,microsec);
	  move->addSubSprite(subsprite);
	  ((CState*)state2)->addAnimation("Move",move);
	} else {
	  AAnimation * move = new ARight(pelle, microsec);
	  move->addSubSprite(subsprite);
	  ((CState*)state2)->addAnimation("Move",move);
	}
	pelle->addComponent("State",state2);
      }
      

    }
    if (pelle!=NULL) {
      CState * state2 = (CState*) pelle->getComponent("State");
      if (state2->getState().compare("Move")!=0) {
	state2->setState("Move");
      }
      state2->update(elapsed.asMicroseconds());
    }
    state->update(elapsed.asMicroseconds());

    window.clear(); // not sure why i do dat
    window.draw(sprite->getSprite() );
    if (pelle !=NULL) {
      window.draw(((CSprite*)pelle->getComponent("Sprite"))->getSprite());
    }

    window.draw(fsprite->getSprite());
    window.display();

  }

return 0;
}

