
#pragma once

namespace GuideCraft {
  class Bus
  {
  public:
    Bus(const std::string& name_)
      : name(name_) {}
    virtual ~Bus() { close(); }

  public:
    void open();
    void close();

  private:
    const std::string name;
    int shm;
    pthread_rwlock_t rwLock;
  };
}
