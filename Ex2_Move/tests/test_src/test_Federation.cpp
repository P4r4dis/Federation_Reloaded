#include "../test_include/test_Federation.hpp"

Federation::Starfleet::Ship::Ship(
    int length, 
    int width,
    std::string name,
    short maxWarp)
    :
    _length(length), _width(width), _name(name), _maxWarp(maxWarp),
    _core(nullptr), _captain(nullptr), _location(EARTH), _home(EARTH)
{
    std::cout   << "The ship USS " << _name << " has been finished." 
                << std::endl
                << "It is " << _length 
                << " m in length and " << _width << " m in width."
                << std::endl
                << "It can go to Warp " << _maxWarp << "!" << std::endl;
}

int             Federation::Starfleet::Ship::getLength(void) const
{
    return _length;
}

int             Federation::Starfleet::Ship::getWidth(void) const
{
    return _width;
}

std::string     Federation::Starfleet::Ship::getName(void) const
{
    return _name;
}

short           Federation::Starfleet::Ship::getMaxWarp(void) const
{
    return _maxWarp;
}

void            Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout   << "USS " << _name << ": The core is set." << std::endl;
}

void            Federation::Starfleet::Ship::promote(Captain *captain)
{
    _captain = captain;
    std::cout   << _captain->getName()
                << ": I'm glad to be the captain of the USS "
                << _name << "." << std::endl;
}

void            Federation::Starfleet::Ship::checkCore(void)
{
    std::cout   << "USS " << _name << ": The core is " 
                << (_core->checkReactor()->isStable() ? "stable" : "unstable")
                << " at the time." << std::endl;
}

Destination     Federation::Starfleet::Ship::getLocation(void) const
{
    return _location;
}

Destination     Federation::Starfleet::Ship::getHome(void) const
{
    return _home;
}

bool            Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && 
        d != _location && 
        _core->checkReactor()->isStable() == true)
    {
        _maxWarp -= warp;
        _location = d;
        return true;
    }
    else
        return false;
}

bool            Federation::Starfleet::Ship::move(int warp)
{
    return move(warp, _home);
}

bool            Federation::Starfleet::Ship::move(Destination d)
{
    return move(_maxWarp, d);
}

bool            Federation::Starfleet::Ship::move(void)
{
    return move(_maxWarp, _home);
}

// FEDERATION::STARFLEET::SHIP
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


Federation::Starfleet::Captain::Captain(std::string name) : _name(name), 
                                                            _age(0)
{}

std::string     Federation::Starfleet::Captain::getName(void)
{
    return _name;
}

int             Federation::Starfleet::Captain::getAge(void)
{
    return _age;
}

void            Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}



// FEDERATION::STARFLEET::CAPTAIN
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

Federation::Ship::Ship(int length, int width, std::string name)
                :   _length(length), _width(width), _name(name), 
                    _maxWarp(1), _core(nullptr), _home(VULCAN), _location(VULCAN)
{
    std::cout   << "The independent ship "
                << _name << " just finished its construction."
                << std::endl
                << "It is " << _length << " m in length and "
                << _width << " m in width." << std::endl;
}

int             Federation::Ship::getLength(void) const
{
    return _length;
}

int             Federation::Ship::getWidth(void) const
{
    return _width;
}

std::string     Federation::Ship::getName(void) const
{
    return _name;
}

void            Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout   << _name << ": The core is set." << std::endl;
}



void            Federation::Ship::checkCore(void)
{
    std::cout   << _name << ": The core is " 
                << (_core->checkReactor()->isStable() ? "stable" : "unstable")
                << " at the time." << std::endl;
}

Destination     Federation::Ship::getLocation(void) const
{
    return _location;
}

Destination     Federation::Ship::getHome(void) const
{
    return _home;
}

bool            Federation::Ship::move(int warp, Destination d)
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

bool            Federation::Ship::move(int warp)
{
    return move(warp, _home);
}

bool            Federation::Ship::move(Destination d)
{
    return move(_maxWarp, d);
}

bool            Federation::Ship::move(void)
{
    return move(_maxWarp, _home);
}
// FEDERATION::SHIP
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


Federation::Starfleet::Ensign::Ensign(std::string name) : _name(name)
{
    std::cout   << "Ensign " << _name 
                << ", awaiting orders." << std::endl; 
}

// Federation::Starfleet::Ensign
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////