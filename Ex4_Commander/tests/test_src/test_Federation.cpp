#include "../test_include/test_Federation.hpp"

Federation::Starfleet::Ship::Ship(
    int length, 
    int width,
    std::string name,
    short maxWarp,
    int torpedo)
    :
    _length(length), _width(width), _name(name), _maxWarp(maxWarp),
    _core(nullptr), _captain(nullptr), _location(EARTH), _home(EARTH),
    _shield(100), _photonTorpedo(torpedo)
{
    std::cout   << "The ship USS " << _name << " has been finished." 
                << std::endl
                << "It is " << _length 
                << " m in length and " << _width << " m in width."
                << std::endl
                << "It can go to Warp " << _maxWarp << "!" << std::endl;
    if (_photonTorpedo > 0)
    {
        std::cout   << "Weapons are set: " << _photonTorpedo << " torpedoes ready."
                    << std::endl;
    }
}

Federation::Starfleet::Ship::Ship() :   _length(289), _width(132), 
                                            _name("Entreprise"), _maxWarp(6),
                                            _core(nullptr), _captain(nullptr), 
                                            _location(EARTH), _home(EARTH),
                                            _shield(100), _photonTorpedo(0)
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

int             Federation::Starfleet::Ship::getTorpedo(void) const
{
    return _photonTorpedo;
}

int             Federation::Starfleet::Ship::getShield(void) const
{
    return _shield;
}

void            Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

void            Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

void            Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (_photonTorpedo > 0)
    {
        _photonTorpedo -= 1;
        std::cout   << _name << ": Firing on target. "
                    <<  _photonTorpedo << " torpedoes remaining." << std::endl;
        target->setShield(target->getShield() - 50 * 1);
        if (target->getShield() < 0)
            target->setShield(0);
        if (_photonTorpedo == 0)
        {
            std::cout   << _name << ": No more torpedo to fire, "
                        << _captain->getName() << "!" << std::endl;
        }
    }
    else
    {
        std::cout   << _name << ": No enough torpedoes to fire, "
                    << _captain->getName() << "!" << std::endl;
    }
}

void            Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (_photonTorpedo >= torpedoes)
    {
        _photonTorpedo -= torpedoes;
        std::cout   << _name << ": Firing on target. "
                    <<  _photonTorpedo << " torpedoes remaining." << std::endl;
        target->setShield(target->getShield() - 50 * torpedoes);
        if (target->getShield() < 0)
            target->setShield(0);
        if (_photonTorpedo == 0)
        {
            std::cout   << _name << ": No more torpedo to fire, "
                        << _captain->getName() << "!" << std::endl;
        }
    }
    else
    {
        std::cout   << _name << ": No enough torpedoes to fire, "
                    << _captain->getName() << "!" << std::endl;
    }
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
                    _maxWarp(1), _core(nullptr), _home(VULCAN), _location(VULCAN),
                    _shield(100)
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

WarpSystem::Core    *Federation::Ship::getCore(void) const
{
    return _core;
}

int             Federation::Ship::getShield(void) const
{
    return _shield;
}

void            Federation::Ship::setShield(int shield)
{
    _shield = shield;
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