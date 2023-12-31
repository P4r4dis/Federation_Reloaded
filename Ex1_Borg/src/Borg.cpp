#include "../include/Borg.hpp"

Borg::Ship::Ship(void) : _side(300), _maxWarp(9), _core(nullptr)
{
    std::cout   << "We are the Borgs."
                << " Lower your shields and surrender yourselves unconditionally."
                << std::endl
                << "Your biological characteristics and technologies will be assimilated."
                << std::endl
                << "Resistance is futile." << std::endl;
}

void    Borg::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
}

void    Borg::Ship::checkCore(void)
{
    std::cout << 
    (_core->checkReactor()->isStable() ? 
    "Everything is in order." : "Critical failure imminent.")
    << std::endl;  
}