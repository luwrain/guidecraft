
#pragma once

#include <cstdint>
namespace GuideCraft {
  class Message
  {
  public:
    Message(char* buf) : data(buf) {}
    Message();
  public:
    uint32_t count;
    uint32_t TimeStep;
    char  *data;
  };
}
