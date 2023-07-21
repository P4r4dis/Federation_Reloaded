#ifndef                             __BORGQUEEN__
    #define                         __BORGQUEEN__

#include <iostream>
#include "test_Borg.hpp"

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

                bool                move(Borg::Ship *ship, Destination dest);
        };
}

#endif //                           __BORGQUEEN__