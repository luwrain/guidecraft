
#pragma once

#include"Bus.h"

namespace GuideCraft {
  class Service
  {
  public:
    Service() {}
    virtual ~Service() {}

  public:
    void run();

  private:
    std::list<std::shared_ptr<Bus> > buses;
  };
}
