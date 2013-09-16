#include "engine2d.h"

using namespace std;
using namespace gs;

int main(int argc, char* argv[])
{
    Engine2D* engine = new Engine2D(argc, argv);
    engine->start();
    delete engine;

    return 0;
}
