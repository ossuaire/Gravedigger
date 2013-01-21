#ifndef __ENVIRONMENTFACTORY_H__
#define __ENVIRONMENTFACTORY_H__

#include <string>
#include "Environment.hpp"

class EnvironmentFactory {

private:

public:

  EnvironmentFactory();
  Environment * get(const std::string name);

};

#endif
