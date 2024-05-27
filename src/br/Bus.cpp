#include"os.h"
#include"config.h"
#include"Bus.h"
#include"test.h"
#include"RwLock.h"
#include <cstdint>
#include <vector>
#include "CircularQueue.h"
#include "Message.h"
#include "cstring"

 
#define TIMESCALE std::chrono::microseconds
#define TIMESCALE_COUNT 1e6
#define TIMESCALE_NAME "us"

using namespace GuideCraft;
uint64_t current_time() {
  auto time_since_epoch = std::chrono::system_clock::now().time_since_epoch();
  auto casted_time = std::chrono::duration_cast<TIMESCALE>(time_since_epoch);
  return casted_time.count();
}
void Bus::open()
{
  int res;
  int shm;
  auto lock_size = sizeof(RwLock);
  auto buffer_size = sizeof(Buf);
  pid_t pid;
  pid = getpid();
  Buf *buf;
  CircularQueue *queue;
  const std::string storage = "/SHM" + name;
  shm  = shm_open(storage.c_str(), O_CREAT | O_RDWR, SHM_MODE);
  if (shm == -1)
    perror("shm_open");
     res = ftruncate(shm,((LIMIT_MESSAGE_SIZE * QUEUE_SIZE)+12800));
	if (res == -1)
	{
		perror("ftruncate");
	}
  Buf * b;


  auto *ptr = mmap(nullptr, ((LIMIT_MESSAGE_SIZE * QUEUE_SIZE)+12800) , PROT_READ | PROT_WRITE,
                   MAP_SHARED, shm, 0);	

  auto *base_address= reinterpret_cast<char*>(ptr);
  auto *queue_address = base_address + buffer_size;
  b= new(base_address) Buf();
  queue = new (queue_address) CircularQueue(b);
  double time_counter = 0;
  std::cout << "Hello World!"<< std::endl;
  int vector_size = 8000;
  auto *rawptr = malloc(vector_size);
  std::memset(rawptr, 255, vector_size);
  Message *msg = reinterpret_cast<Message *>(rawptr);
  msg->count = 0;
  

  Elem el;
  el.sz = 8000;

  int seconds = 10;
  auto start = std::chrono::steady_clock::now();
  for (auto now = start; now < start + std::chrono::seconds(seconds);
       now = std::chrono::steady_clock::now()) 
  {
    msg->count++;
    msg->TimeStep = current_time();
 //   std::cout<<msg->TimeStep <<' ';
    el.msg = reinterpret_cast<char *>(msg);
    queue->write(&el); 
  }
}
void Bus::close()
{
  }
