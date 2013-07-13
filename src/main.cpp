#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#ifdef __APPLE__                            // to allow the usage of relative
#include "CoreFoundation/CoreFoundation.h"  // path on Mac OS X
#endif
#include "CharacterFactory.hpp"
#include "EnvironmentFactory.hpp"
#include "ItemFactory.hpp"
#include "AThrow.hpp"
 
using namespace std;

// this makes OS X relative paths work in C++ by changing directory to the
// Resources folder inside the .app bundle
#ifdef __APPLE__
void ensure_mac_compatibility() {
  CFBundleRef mainBundle = CFBundleGetMainBundle();
  CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(mainBundle);
  char path[PATH_MAX];

  !CFURLGetFileSystemRepresentation(resourcesURL,
                                    TRUE,
                                    (UInt8 *) path,
                                    PATH_MAX);
  CFRelease(resourcesURL);
  chdir(path);
}
#endif

int main()
{
#ifdef __APPLE__    
  ensure_mac_compatibility();
#endif
  sf::RenderWindow window(sf::VideoMode(800, 600), "Gravedigger");
  window.setFramerateLimit(60);

  // Character
  CharacterFactory cf;
  Character * gravedigger = cf.get("Gravedigger");
  CSprite * sprite = (CSprite *) gravedigger->getComponent("Sprite");
  CState * state = (CState*) gravedigger->getComponent("State");
  sprite->updatePosition();

  // Environment
  EnvironmentFactory ef;
  Environment * floor = ef.get("Floor");
  CSprite * fsprite = (CSprite *) floor->getComponent("Sprite");
  fsprite->updatePosition();

  // Main loop
  sf::CircleShape radiusHit;
  radiusHit.setRadius(80);
  radiusHit.setOutlineColor(sf::Color::Red);
  radiusHit.setFillColor(sf::Color::Black);
  radiusHit.setOutlineThickness(5);
  sf::CircleShape radiusStrength;
  radiusStrength.setRadius(0);
  bool thrown = false;
  bool wasPressed = false;
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
      if (event.type == sf::Event::MouseButtonReleased) {
	ACThrow * throwAction = (ACThrow*) gravedigger->getComponent("Throw");
	throwAction->setX(event.mouseButton.x);
	throwAction->setY(event.mouseButton.y);
	throwAction->execute();
	thrown  = true;
	wasPressed = false;
	radiusStrength.setRadius(0);
      }
      if (event.type == sf::Event::MouseButtonPressed) {
	wasPressed = true;
      }
      

    }

    // TODO register elements
    // Ask in collision handler item to draw
    state->update(elapsed.asMicroseconds());

    window.clear();
    if (wasPressed) {
      CPosition * position=(CPosition*)gravedigger->getComponent("Position");
      int x=  position->getX(); // already set to middle of character
      int y= position->getY() -
	(sprite->getSprite()).getLocalBounds().height/2; 
      radiusHit.setOrigin(radiusHit.getRadius(),radiusHit.getRadius());
      radiusHit.setPosition(x,y);

      radiusStrength.setRadius(std::min(80.f,radiusStrength.getRadius()+1) );
      radiusStrength.setOrigin(radiusStrength.getRadius(),
				 radiusStrength.getRadius());
      radiusStrength.setPosition(x,y); // TOFIX setOrigin
      window.draw(radiusHit);
      window.draw(radiusStrength);
    }
    window.draw(sprite->getSprite());
    if (thrown) {
      GameObject * shovel;
      shovel = ((ACThrow*)gravedigger->getComponent("Throw"))->getItem();
      ((CState*)shovel->getComponent("State"))->update(elapsed.asMicroseconds());
      window.draw(((CSprite*)shovel->getComponent("Sprite"))->getSprite());
    }

    window.draw(fsprite->getSprite());
    window.display();

  }

return 0;
}

