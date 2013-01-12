#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CharacterFactory.hpp"

using namespace std;

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Gravedigger");
  window.setFramerateLimit(60);

  CharacterFactory cf;
  Character * gravedigger = cf.get("Gravedigger");

  while (window.isOpen()) {
    sf::Event event;
    sf::Clock clock;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
	window.close();
      }
      if ((event.type == sf::Event::KeyPressed) &&
	  (event.key.code == sf::Keyboard::D)) { // right
	CPosition * position = (CPosition*)
	  gravedigger->getComponent("Position");
	position->setX(position->getX() + 10);
      }
      if ((event.type == sf::Event::KeyPressed) &&
	  (event.key.code == sf::Keyboard::Q)) { // right
	CPosition * position = (CPosition*)
	  gravedigger->getComponent("Position");
	position->setX(position->getX()- 10);
      }
    }
    
    CSprite * sprite = (CSprite *) gravedigger->getComponent("Sprite");
    sprite->updatePosition();
    window.draw(sprite->getSprite() );
    window.display();
    window.clear(); // not sure why i do dat
  }

  return 0;
}

