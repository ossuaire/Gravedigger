#ifndef __RTREE_H__
#define __RTREE_H__

#include <vector>
#include "CBoundingBox.hpp"

class RTree;

class RTree {

private:

  int depth;
  bool isLeaf;
  RTree * parent;
  CBoundingBox * boundingBox;

  // Sibling of the tree. For instance, can be RTree or CBoundingBox component
  std::vector<RTree *> siblings;

public:

  RTree(RTree * _parent, CBoundingBox * _boundingBox);

  CBoundingBox * getBoundingBox();
  RTree * getParent();
  bool getIsLeaf();
  int getDepth();

  void setIsLeaf(const bool _isLeaf);
  void setDepth(const int _depth);
  void setBoundingBox(CBoundingBox * _boundingBox);

  void addSibling(CBoundingBox * _sibling);

};

#endif
