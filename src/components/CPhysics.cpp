#include "CPhysics.hpp"


CPhysics::CPhysics(GameObject * parent, b2Body * _body): CComponent(parent){
  body = _body;
}

void CPhysics::setBody(b2Body * _body){
  body = _body;
}

b2Body * CPhysics::getBody(){
  return body;
}
