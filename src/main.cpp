#include "engine2d.h"

using namespace std;
using namespace gs;

int main(int argc, char* argv[])
{
    GsEngine2D* engine = new GsEngine2D(argc, argv);
    engine->start();
    delete engine;

    return 0;
}
