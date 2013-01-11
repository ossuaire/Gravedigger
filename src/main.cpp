#include <iostream>
#include <SFML/Window.hpp>
#include "Gravedigger.hpp"

using namespace std;

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Gravedigger");
  //std::cout << "Dat iz a tasty burger" << std::endl;

  Gravedigger gd;

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
	window.close();
      }
    }
    
    window.draw(gd.gravediggerSprite );
    window.display();
    window.clear(); // not sure why i do dat
  }

  return 0;
}

