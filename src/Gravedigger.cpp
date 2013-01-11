#include "Gravedigger.hpp"

Gravedigger::Gravedigger(){
  
  if (!texture.loadFromFile("material/img/chara-design/gravedigger.png")){
    std::cout << "Gravedigger Sprite failed to loaded" <<std::endl;
  }
  
  
  gravediggerSprite.setTexture(texture);
  gravediggerSprite.setScale(5.0,5.0);
  gravediggerSprite.setPosition(100,25);

}
