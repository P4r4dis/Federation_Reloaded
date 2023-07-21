#ifndef                             __ADMIRAL__
    #define                         __ADMIRAL__

#include <iostream>
#include "Federation.hpp"

namespace                           Federation
{
    namespace                       Starfleet
    {
        class                       Admiral;
    }
}

namespace                           Federation
{
    namespace                       Starfleet
    {
        class                       Admiral
        {
            private:
                std::string         _name;
            public:
                Admiral(std::string name);

                std::string         getName(void) const;

                bool                (Federation::Starfleet::Ship::*movePtr) (Destination d);
                bool                move(Federation::Starfleet::Ship *ship, Destination d);

                void                (Federation::Starfleet::Ship::*firePtr) (Borg::Ship *target);
                void                fire(Federation::Starfleet::Ship *ship, Borg::Ship *target);
        };
    }
}

#endif //                           __ADMIRAL__