
#include"os.h"
#include"config.h"
#include"Bus.h"

using namespace GuideCraft;
using namespace std;

void Bus::open()
{
  shm = shm_open(name.c_str(), O_CREAT | O_RDWR, SHM_MODE);
  if (shm == -1)
    perror("mq_open()");
  }

void Bus::stop()
{
  }
