#include <iostream>
#include <SFML/Window.hpp>

using namespace std;

int main()
{
  sf::Window window(sf::VideoMode(800, 600), "Gravedigger");
  //std::cout << "Dat iz a tasty burger" << std::endl;

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
	window.close();
      }
    }
  }

  return 0;
}

