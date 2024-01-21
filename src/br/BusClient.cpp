
#include"os.h"
#include"config.h"
#include"BusClient.h"

using namespace GuideCraft;
using namespace std;

void BusClient::create()
{
}

void BusClient::run()
{
  thrOut = auto_ptr<thread>(new thread([this]{ outgoingTracker(); }));
}

void BusClient::outgoingTracker()
{
  while(1)
    {
      std::unique_lock<std::mutex> lock(mutexOut);
      cvOut.wait(lock, [=] { return pending.empty(); });
    }
}

void BusClient::enqueueMessage(const Message& msg)
{
  std::unique_lock<std::mutex> lock(mutexOut);
  pending.push_back(msg);
  cvOut.notify_one();
}
