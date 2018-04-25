#include "upm/interfaces/UpmObject.hpp"
#include <string>
#include <iostream>

using namespace upm;

class MockSensor : public UpmObject
{
public:
  MockSensor(std::string initStr) : UpmObject(initStr) {}
  MockSensor() : UpmObject() {}
  ~MockSensor() {}
};

int main()
{
  /* Example using gpio pin 463 on UP2 Board*/
  MockSensor mockSensor("g:5:1-upm_attr1:upm_attr2:upm_attr3");

  return 0;
}