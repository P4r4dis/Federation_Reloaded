#include "../test_include/test_Borg.hpp"

Borg::Ship::Ship(void) :    _side(300), _maxWarp(9), _core(nullptr), 
                            _home(UNICOMPLEX), _location(_home)

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

bool            Borg::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && 
        d != _location && 
        _core->checkReactor()->isStable() == true)
    {
        _location = d;
        return true;
    }
    else
        return false;
}

bool            Borg::Ship::move(int warp)
{
    return move(warp, _home);
}

bool            Borg::Ship::move(Destination d)
{
    return move(_maxWarp, d);
}

bool            Borg::Ship::move(void)
{
    return move(_maxWarp, _home);
}

Destination     Borg::Ship::getHome(void) const
{
    return _home;
}

Destination     Borg::Ship::getLocation(void) const
{
    return _location;
}