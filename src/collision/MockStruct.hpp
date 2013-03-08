#ifndef __MOCKSTRUCT_H__
#define __MOCKSTRUCT_H__

#include "ICollisionStruct.hpp"
//#include "CBoundingBox.hpp"

//class ICollisionStruct;

class MockStruct : public ICollisionStruct{

private:

  std::vector<CBoundingBox *> boundingBoxes;

public:
  MockStruct();
  
  void addBoundingBox(CBoundingBox* _boundingBox);

  std::vector<CBoundingBox *> search(CBoundingBox * _boundingBox);
};

#endif
