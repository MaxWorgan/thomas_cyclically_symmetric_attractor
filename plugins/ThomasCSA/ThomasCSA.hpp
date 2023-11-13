// PluginThomasCSA.hpp
// Max Worgan (m.worgan@sussex.ac.uk)

#pragma once

#include "SC_PlugIn.hpp"

namespace Thomas {


struct vec {
    double x;
    double y;
    double z;
};

class ThomasCSA : public SCUnit {
public:
    ThomasCSA();

private:
    vec pos;

    float b;
    float dt;

    void next(int nSamples);
    vec stepRK4(vec position, float stepSize);


};

} // namespace Thomas
