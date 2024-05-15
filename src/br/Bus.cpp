#include"os.h"
#include"config.h"
#include"Bus.h"
#include"test.h"
#include"RwLock.h"
#include <cstdint>

#define STORAGE_ID "/SHM_TEST"  

using namespace GuideCraft;
using namespace std;
void Bus::open()
{
  int res;
  int shm;
  test* test_;
  auto test_size = sizeof(test);
  auto lock_size = sizeof(RwLock);

  pid_t pid;
  pid = getpid();


  shm  = shm_open(STORAGE_ID, O_CREAT | O_RDWR, SHM_MODE);
  if (shm == -1)
    perror("shm_open");
     res = ftruncate(shm,sizeof(test));
	if (res == -1)
	{
		perror("ftruncate");
	}

  auto *ptr = mmap(nullptr, sizeof(test) , PROT_READ | PROT_WRITE,
                   MAP_SHARED, shm, 0);	

  auto *base_address= reinterpret_cast<uintptr_t*>(ptr);
  auto *test_address = base_address;
  auto *int_address = base_address + lock_size;

  test_ = new (test_address) test();
  uint8_t count = 1;
  uint8_t count2 = 4;
  double time_counter = 0;

  clock_t this_time = clock();
  clock_t last_time = this_time;

   while(true)
    { 
        this_time = clock();

        time_counter += (double)(this_time - last_time);

        last_time = this_time;

        if(time_counter > (double)(3 * CLOCKS_PER_SEC))
        {
            time_counter -= (double)(3 * CLOCKS_PER_SEC);
            test_->write(int_address, &count2, sizeof(count2));
            std::cout << "PID: " << pid<< " send: " << +count2 <<std::endl;

            count2 ++;
        }
    }

    return ;


}
void Bus::close()
{
  }
