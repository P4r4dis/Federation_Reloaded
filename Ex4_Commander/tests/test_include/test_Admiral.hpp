#ifndef                             __ADMIRAL__
    #define                         __ADMIRAL__

#include <iostream>

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
            public:
                Admiral(std::string name);

                std::string         getName(void) const;
            private:
                std::string         _name;
        };
    }
}

#endif //                           __ADMIRAL__