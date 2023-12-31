#include "../test_include/test_Federation.hpp"

Federation::Starfleet::Ship::Ship(
    int length, 
    int width,
    std::string name,
    short maxWarp)
    :
    _length(length), _width(width), _name(name), _maxWarp(maxWarp)
{
    std::cout   << "The ship USS " << _name << " has been finished." 
                << std::endl
                << "It is " << _length 
                << " m in length and " << _width << " m in width."
                << std::endl
                << "It can go to Warp " << _maxWarp << "!" << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
                :   _length(length), _width(width), _name(name)
{
    std::cout   << "The independent ship "
                << _name << " just finished its construction."
                << std::endl
                << "It is " << _length << " m in length and "
                << _width << " m in width." << std::endl;
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

void            Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout   << _name << ": The core is set." << std::endl;
}

void            Federation::Starfleet::Ship::checkCore(void)
{
    std::cout   << "USS " << _name << ": The core is " 
                << (_core->checkReactor()->isStable() ? "stable" : "unstable")
                << " at the time." << std::endl;
}

void            Federation::Ship::checkCore(void)
{
    std::cout   << _name << ": The core is " 
                << (_core->checkReactor()->isStable() ? "stable" : "unstable")
                << " at the time." << std::endl;
}