#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CharacterFactory.hpp"

using namespace std;

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Gravedigger");
  //std::cout << "Dat iz a tasty burger" << std::endl;

  CharacterFactory cf;
  Character * gravedigger = cf.get("Gravedigger");

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
	window.close();
      }
    }
    
    //window.draw(gd.gravediggerSprite );
    window.display();
    window.clear(); // not sure why i do dat
  }

  return 0;
}

