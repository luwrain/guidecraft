
#pragma once

#include "Message.h"

namespace GuideCraft {
  class Listener
  {
  public:
    virtual void onMessage(Message msg) = 0;
  };
}
