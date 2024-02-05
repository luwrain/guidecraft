
#pragma once

#include"Message.h"

namespace GuideCraft {
  class Client
  {
  public:
    Client(const std::string& name_): name(name_) {}

  public:
    void connectSync(const std::string& busName);
    void messageSend(Message msg);

  public:
    const std::string name;
  };
}
