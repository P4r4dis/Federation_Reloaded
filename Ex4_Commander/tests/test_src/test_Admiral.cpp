#include "../test_include/test_Admiral.hpp"

namespace               Federation
{
    namespace           Starfleet
    {
        Admiral::Admiral(std::string name) :    _name(name),
                                                movePtr(&Federation::Starfleet::Ship::move)
        {
            std::cout   << "Admiral " << _name 
                        << " ready for action." << std::endl;           
        }

        std::string     Admiral::getName(void) const
        {
            return _name;
        }

        bool            Admiral::move(Federation::Starfleet::Ship *ship, Destination d)
        {
            return (ship->*movePtr)(d);
        }

    }
}