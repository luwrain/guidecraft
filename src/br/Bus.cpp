
#include"os.h"
#include"config.h"
#include"Bus.h"

struct Header {
  pthread_rwlock_t rwLock;
};

using namespace GuideCraft;
using namespace std;

void Bus::open()
{
  shm = shm_open(name.c_str(), O_CREAT | O_RDWR, SHM_MODE);
  if (shm == -1)
    perror("shm_open");
pthread_rwlockattr_t attr;
int res = pthread_rwlockattr_init(&attr);
 if (res != 0)
   cerr << "pthread_rwlockattr_init failed" << endl;
  res = pthread_rwlockattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
  if (res != 0)
    cerr << "pthread_rwlockattr_setpshared failed" << endl;
res = pthread_rwlock_init(&rwLock, &attr);
  if (res != 0)
    cerr << "pthread_rwlock_init failed " << endl;
  //  pthread_rwlockattr_destroy(&attr);
  cout << sizeof(pthread_rwlock_t) << endl;
  const Header h = {
    .rwLock = rwLock
  };
  write(shm, &h, sizeof(Header));
  }

void Bus::close()
{
  }
