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
	  (state->getState().compare("Right")!=0)) { // right
	state->setState("Right");
      }
      if ((event.type == sf::Event::KeyPressed) &&
	  (event.key.code == sf::Keyboard::Q) &&
	  (state->getState().compare("Left")!=0)) { // left
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
    }
    state->update(elapsed.asMicroseconds());

    window.draw(sprite->getSprite() );
    window.draw(fsprite->getSprite());
    window.display();
    window.clear(); // not sure why i do dat
  }

return 0;
}

