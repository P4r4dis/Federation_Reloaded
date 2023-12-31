#ifndef                         __BORG__
    #define                     __BORG__

#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace                       Borg
{
    class                       Ship
    {
        public:
            Ship(void);
            void                setupCore(WarpSystem::Core *core);
            void                checkCore(void);
            Destination         getHome(void) const;
            Destination         getLocation(void) const;
            bool                move(int warp, Destination d);
            bool                move(int warp);
            bool                move(Destination d);
            bool                move();
        private:
            int                 _side;
            short               _maxWarp;
            WarpSystem::Core    *_core;
            Destination         _home;
            Destination         _location;
    };
}
#endif //                       __BORG__