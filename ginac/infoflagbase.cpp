/*
 * File:   infoflagbase.cpp
 * Author: Ralf Stephan <ralf@ark.in-berlin.de>
 *
 * Created on August 3, 2015, 9:31 AM
 */

#include <stdexcept>
#include "infoflagbase.h"

namespace GiNaC {

static bool initialized = false;

infoflagbase::infoflagbase()
{
        if (not initialized)
                init_index();
}

//------------------------------------------
constexpr unsigned const infoflagbase::flags[];
unsigned infoflagbase::index[info_flags::relation];

void infoflagbase::init_index()
{
        unsigned ctr = 0;
        for (unsigned i : flags)
                index[i] = ctr++; 
        initialized = true;
}

bool infoflagbase::get(unsigned flag) const
{
        if (flag > info_flags::relation)
                throw(std::runtime_error("requested wrong info flag"));
        return bits[index[flag]];
}


} // namespace GiNaC
