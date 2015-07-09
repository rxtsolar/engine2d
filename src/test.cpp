#include <iostream>
#include "vect2.h"
using namespace std;
using namespace gs;

int main(void)
{
    GsVect2i vi(0, 1);
    GsVect2d vd(0.5, 1.6);
    vi += (GsVect2i)vd;
    vd += vi;
    cout << vi.getX() << ' ' << vi.getY() << endl;
    cout << vd.getX() << ' ' << vd.getY() << endl;
    return 0;
}
