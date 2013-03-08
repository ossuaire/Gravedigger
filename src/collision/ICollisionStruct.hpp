#ifndef __ICOLLISIONSTRUCT_H__
#define __ICOLLISIONSTRUCT_H__

#include "CBoundingBox.hpp"
#include <vector>

class ICollisionStruct {

private:

public:

  virtual void addBoundingBox(CBoundingBox * _boundingBox) = 0;

  virtual std::vector<CBoundingBox *> search(CBoundingBox * _boundingBox) = 0;
};

#endif
