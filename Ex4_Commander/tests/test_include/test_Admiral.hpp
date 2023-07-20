#ifndef                             __ADMIRAL__
    #define                         __ADMIRAL__

#include <iostream>
#include "test_Federation.hpp"

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


        };
    }
}

#endif //                           __ADMIRAL__