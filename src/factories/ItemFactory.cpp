#include "ItemFactory.hpp"

ItemFactory::ItemFactory() {
  //nothin'
}

Item * ItemFactory::get(const std::string name) {
  Item * item;
  
  if (name.compare(std::string("Shovel"))==0) {
    item = new Item("Shovel");
    CComponent * position = new CPosition(item,0,0);
    //    CComponent * boundingbox = new CBoundingBox(item,
    //						sf::IntRect(0,0,9,9));
    CComponent * sprite;
    sprite = new CSprite(item,
			  "material/img/chara-design/zelda-heart.png",
			  5.0);

    CComponent * speed = new CSpeed(item,0,0,10,10);

    sf::Int64 microsec = sf::seconds(1.0).asMicroseconds();
    CComponent * state = new CState(item);
    sf::IntRect subsprite(0,0,9,9);
    AAnimation * move = new AThrow(item,microsec);
    move->addSubSprite(subsprite);
    ((CState*)state)->addAnimation("Move",move);

    item->addComponent("State",state);
    item->addComponent("Speed",speed);
    item->addComponent("Position",position);
    item->addComponent("Sprite",sprite);
  }

  return item;
}
