#include "CollisionHandler.hpp"

CollisionHandler::CollisionHandler(ICollisionStruct * _boundingBoxes) {
  boundingBoxes = _boundingBoxes;
}

ICollisionStruct * CollisionHandler::getBoundingBoxes() {
  return boundingBoxes;
}

void CollisionHandler::solveCollision(CBoundingBox* boundingBox) {
  std::vector<CBoundingBox*> results = boundingBoxes->search(boundingBox);
  // TODO: resolve the collision
}
