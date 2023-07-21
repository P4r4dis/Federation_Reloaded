#ifndef                             __BORGQUEEN__
    #define                         __BORGQUEEN__

#include <iostream>
#include "Borg.hpp"

namespace                           Borg
{
        class                       BorgQueen;
}

namespace                           Borg
{
        class                       BorgQueen
        {
            public:
                BorgQueen(void);

                bool                (Borg::Ship::*movePtr)(Destination d);
                void                (Borg::Ship::*firePtr)(Federation::Starfleet::Ship *ship);
                void                (Borg::Ship::*destroyPTr)(Federation::Ship *ship);

                bool                move(Borg::Ship *ship, Destination dest);
                void                fire(Borg::Ship *ship, Federation::Starfleet::Ship *target);
                void                fire(Borg::Ship *ship, Federation::Ship *target);
        };
}

#endif //                           __BORGQUEEN__