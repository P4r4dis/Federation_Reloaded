#include "../test_include/test_BorgQueen.hpp"

namespace   Borg
{
    BorgQueen::BorgQueen(void) :    movePtr(&Borg::Ship::move)
    {}

    bool    BorgQueen::move(Borg::Ship *ship, Destination dest)
    {
        return (ship->*movePtr)(dest);
    }
}