#include "../include/BorgQueen.hpp"

namespace   Borg
{
    BorgQueen::BorgQueen(void) :    movePtr(&Borg::Ship::move),
                                    firePtr(&Borg::Ship::fire),
                                    destroyPTr(&Borg::Ship::fire)
    {}

    bool    BorgQueen::move(Borg::Ship *ship, Destination dest)
    {
        return (ship->*movePtr)(dest);
    }

    void    BorgQueen::fire(Borg::Ship *ship, Federation::Starfleet::Ship *target)
    {
        (ship->*firePtr)(target);
    }

    void    BorgQueen::fire(Borg::Ship *ship, Federation::Ship *target)
    {
        (ship->*destroyPTr)(target);
    }
}