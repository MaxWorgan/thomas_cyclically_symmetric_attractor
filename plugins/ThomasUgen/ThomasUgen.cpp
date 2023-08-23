// PluginThomasUgen.cpp
// Max Worgan (m.worgan@sussex.ac.uk)

#include "SC_PlugIn.hpp"
#include "ThomasUgen.hpp"

static InterfaceTable* ft;

namespace Thomas {

ThomasUgen::ThomasUgen() {
    mCalcFunc = make_calc_function<ThomasUgen, &ThomasUgen::next>();
    next(1);
}

void ThomasUgen::next(int nSamples) {
    const float* input = in(0);
    const float* gain = in(1);
    float* outbuf = out(0);

    // simple gain function
    for (int i = 0; i < nSamples; ++i) {
        outbuf[i] = input[i] * gain[i];
    }
}

} // namespace Thomas

PluginLoad(ThomasUgenUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<Thomas::ThomasUgen>(ft, "ThomasUgen", false);
}
