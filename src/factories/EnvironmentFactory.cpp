#include "EnvironmentFactory.hpp"

#ifndef METERPERPIXEL
#define METERPERPIXEL 0.0210526
#endif

EnvironmentFactory::EnvironmentFactory(b2World * _world){
  world = _world;
}

Environment * EnvironmentFactory::get(const std::string name) {
  Environment * environment;
  
  // Definition of people body
  b2BodyDef environmentBodyDef;
  environmentBodyDef.type = b2_staticBody;
  environmentBodyDef.position.Set(0,0);
  environmentBodyDef.angle = 0;

  if (name.compare(std::string("Floor"))==0) {
    environment = new Environment(std::string("Floor"));

    // creating physics
    environmentBodyDef.position.Set(256*METERPERPIXEL, 300*METERPERPIXEL);
    b2Body * floorBody = world->CreateBody(&environmentBodyDef);
    b2PolygonShape boxShape;
    boxShape.SetAsBox(256*METERPERPIXEL,16*METERPERPIXEL);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = 1;
    boxFixtureDef.friction = 1.0;
    floorBody->CreateFixture(&boxFixtureDef);

    CComponent * physics = new CPhysics(environment,floorBody);

    CComponent * sprite =
      new CSprite(environment,
		  std::string("../material/img/misc/brick.png"),
		  2.0,
		  true);
    ((CSprite *) sprite)->updateSubSprite(0,0,256,16);
    ((CSprite *) sprite)->setOrigin("middle","middle");
    environment->addComponent(std::string("Physics"),physics);
    environment->addComponent(std::string("Sprite"),sprite);
  }

  return environment;
}
