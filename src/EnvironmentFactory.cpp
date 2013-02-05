#include "EnvironmentFactory.hpp"

EnvironmentFactory::EnvironmentFactory() {
  //nothin'
}

Environment * EnvironmentFactory::get(const std::string name) {
  Environment * environment;
  
  if (name.compare(std::string("Floor"))==0) {
    environment = new Environment(std::string("Floor"));
    CComponent * position = new CPosition(environment,50,240);
    CComponent * boundingbox = new CBoundingBox(environment,
						sf::IntRect(50,240,256,16));
    CComponent * sprite =
      new CSprite(environment,
		  std::string("material/img/misc/brick.png"),
		  2.0,
		  true);
    ((CSprite *) sprite)->updateSubSprite(0,0,256,16);
    environment->addComponent(std::string("Position"),position);
    environment->addComponent(std::string("BoundingBox"),boundingbox);
    environment->addComponent(std::string("Sprite"),sprite);
  }

  return environment;
}
