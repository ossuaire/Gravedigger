#include "RTree.hpp"

RTree::RTree(RTree * _parent, CBoundingBox * _boundingBox) {
  parent = _parent;
  if (parent==NULL) {
    depth = 0;
  } else {
    depth = parent->getDepth() + 1;
  };
  boundingBox = _boundingBox;
}

CBoundingBox * RTree::getBoundingBox(){
  return boundingBox;
}

RTree * RTree::getParent(){
  return parent;
}

bool RTree::getIsLeaf(){
  return isLeaf;
}

int RTree::getDepth(){
  return depth;
}

void RTree::setIsLeaf(const bool _isLeaf){
  isLeaf = _isLeaf;
}

void RTree::setDepth(const int _depth){
  depth = _depth;
}

void RTree::setBoundingBox(CBoundingBox * _boundingBox){
  boundingBox = _boundingBox;
}

void addSibling(CBoundingBox * _sibling){
  // tricky algorithm wiz heuristicz and stuff!
}
