#include "../include/WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor(void) : _stability(true)
{}

bool                        WarpSystem::QuantumReactor::isStable(void)
{
    return _stability;
}

void                        WarpSystem::QuantumReactor::setStability(bool stability)
{
    _stability = stability;
}


WarpSystem::Core::Core(QuantumReactor *QR) :    _QR(QR)
{}

WarpSystem::QuantumReactor  *WarpSystem::Core::checkReactor(void)
{
    return _QR;
}