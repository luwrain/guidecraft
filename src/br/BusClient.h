
#pragma once

#include"Message.h"

namespace GuideCraft {
  class BusClient
  {
  public:
    BusClient(int id_): id(id_) {}
    virtual ~BusClient() {}

  public:
    void create();
    void run();
    void enqueueMessage(const Message& msg);

  private:
    void outgoingTracker();

  private:
    const int id;
    std::list<Message> pending;
    mqd_t mqOut;
    std::auto_ptr<std::thread> thrOut;
    std::condition_variable cvOut;
    std::mutex mutexOut;
  };
}
