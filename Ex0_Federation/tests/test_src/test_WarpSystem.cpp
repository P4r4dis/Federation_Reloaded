#include "../test_include/test_WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor(void) : _stability(true)
{}

bool    WarpSystem::QuantumReactor::isStable(void)
{
    return _stability;
}

void    WarpSystem::QuantumReactor::setStability(bool stability)
{
    _stability = stability;
}