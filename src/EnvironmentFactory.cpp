#include "EnvironmentFactory.hpp"

EnvironmentFactory::EnvironmentFactory() {
  //nothin'
}

Environment * EnvironmentFactory::get(const std::string name) {
  Environment * environment;
  
  if (name.compare(std::string("floor"))) {
    environment = new Environment(std::string("floor"));
    
  }

  return environment;
}
