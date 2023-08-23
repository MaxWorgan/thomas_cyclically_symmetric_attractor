// PluginThomasUgen.hpp
// Max Worgan (m.worgan@sussex.ac.uk)

#pragma once

#include "SC_PlugIn.hpp"

namespace Thomas {

class ThomasUgen : public SCUnit {
public:
    ThomasUgen();

    // Destructor
    // ~ThomasUgen();

private:
    // Calc function
    void next(int nSamples);

    // Member variables
};

} // namespace Thomas
