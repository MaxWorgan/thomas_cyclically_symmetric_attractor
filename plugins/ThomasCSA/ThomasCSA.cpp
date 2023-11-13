// PluginThomasCSA.cpp
// Max Worgan (m.worgan@sussex.ac.uk)

#include "SC_PlugIn.hpp"
#include "ThomasCSA.hpp"
#define ONESIXTH 0.1666666666666667

static InterfaceTable* ft;

namespace Thomas {

ThomasCSA::ThomasCSA() {
    mCalcFunc = make_calc_function<ThomasCSA, &ThomasCSA::next>();
    pos.x = 0.4;
    pos.y = 0.3;
    pos.z = 0.1;
    dt = 0.01;
    b = 0.19;
    next(1);
}

void ThomasCSA::next(int numSamples) {

    dt   = in0(0);
    b    = in0(1);

    float* outx = out(0);
    float* outy = out(1);
    float* outz = out(2);


    for(size_t i = 0; i < numSamples; ++i) {
        pos   = stepRK4(pos, dt);

        outx[i] = pos.x;
        outy[i] = pos.y;
        outz[i] = pos.z;

    }

}
vec ThomasCSA::stepRK4(vec position, float dt){
    float k1x = dt * ( -b * position.x + sin(position.y));
    float k1y = dt * ( -b * position.y + sin(position.z));
    float k1z = dt * ( -b * position.z + sin(position.x));

    float kxHalf = k1x/2.0;
    float kyHalf = k1y/2.0;
    float kzHalf = k1z/2.0;

    float k2x = dt * ( -b * (position.x + kxHalf) + sin(position.y + kyHalf));
    float k2y = dt * ( -b * (position.y + kyHalf) + sin(position.z + kzHalf));
    float k2z = dt * ( -b * (position.z + kzHalf) + sin(position.x + kxHalf));

    kxHalf = k2x/2.0;
    kyHalf = k2y/2.0;
    kzHalf = k2z/2.0;
    
    float k3x = dt * ( -b * (position.x + kxHalf) + sin(position.y + kyHalf));
    float k3y = dt * ( -b * (position.y + kyHalf) + sin(position.z + kzHalf));
    float k3z = dt * ( -b * (position.z + kzHalf) + sin(position.x + kxHalf));
    
    float k4x = dt * ( -b * (position.x + k3x) + sin(position.y + k3y));
    float k4y = dt * ( -b * (position.y + k3y) + sin(position.z + k3z));
    float k4z = dt * ( -b * (position.z + k3z) + sin(position.x + k3x));


    vec myVec;

    myVec.x = position.x + (k1x + 2.0*(k2x + k3x) + k4x) * ONESIXTH;
	myVec.y = position.y + (k1y + 2.0*(k2y + k3y) + k4y) * ONESIXTH;
	myVec.z = position.z + (k1z + 2.0*(k2z + k3z) + k4z) * ONESIXTH;


    return myVec;

}

} // namespace Thomas

PluginLoad(ThomasCSA) {
    // Plugin magic
    ft = inTable;
    registerUnit<Thomas::ThomasCSA>(ft, "ThomasCSA", false);
}
