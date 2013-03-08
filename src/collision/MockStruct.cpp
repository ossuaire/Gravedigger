#include "MockStruct.hpp"

MockStruct::MockStruct(){
}

void MockStruct::addBoundingBox(CBoundingBox * _boundingBox){
  boundingBoxes.push_back(_boundingBox);
}

std::vector<CBoundingBox *> MockStruct::search(CBoundingBox * _boundingBox) {
  return boundingBoxes;
};
