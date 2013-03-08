#ifndef __COLLISIONHANDLER_H__
#define __COLLISIONHANDLER_H__

#include "ICollisionStruct.hpp"

class CollisionHandler {

private:
  
  ICollisionStruct * boundingBoxes;

public:
  
  CollisionHandler(ICollisionStruct * _boundingBoxes);
  
  ICollisionStruct * getBoundingBoxes();
  
  void solveCollision(CBoundingBox * boundingBox);
};

#endif
