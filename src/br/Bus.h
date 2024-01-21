
#pragma once

#include"BusClient.h"

namespace GuideCraft {
  class Bus
  {
  public:
    Bus(const std::string& name_)
      : name(name_) {}
    virtual ~Bus() { stop(); }

  public:
    void open();
    void stop();

  private:
    const std::string name;
    int shm;
  };
}
