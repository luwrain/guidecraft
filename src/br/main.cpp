
#include"os.h"
#include"Service.h"


using namespace GuideCraft;
using namespace std;

class CmdLine
{
public:
  CmdLine(int argc, char* argv[]);

public:
  string action;

    private:

private:
  vector<string> args;
};

void printHelp();

int main(int argc, char* argv[])
{
  /*
  CmdLine cmdLine(argc, argv);
  if (cmdLine.action == "help")
    {
      printHelp();
      return 0;
    }
  */
  Service serv;
  serv.run();
  printHelp();
}

CmdLine::CmdLine(int argc, char* argv[])
{
  for(int i = 0;i < argc;i++)
    args.push_back(argv[i]);
  for(auto a = args.begin();a != args.end();a++)
    {
      if (*a == "--help" || *a == "-h")
	{
	  action = "help";
	  return;
	}
    }
}


void printHelp()
{
  cout << "GuideCraft: A screen reader for the blind and visually-impaired" << endl;
  cout << "Copyright (c) 2023 The LUWRAIN Project (please visit https://luwrain.org for more information)" << endl << endl;
}
