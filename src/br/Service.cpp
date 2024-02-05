
#include"os.h"
#include"Service.h"
#include"Bus.h"

using namespace GuideCraft;
using namespace std;

void Service::run()
{
  GuideCraft::Bus b("proba");
  b.open();
}
