#ifndef                         __BORG__
    #define                     __BORG__

#include <iostream>
#include "test_WarpSystem.hpp"
#include "Destination.hpp"

namespace                       Borg
{
    class                       Ship
    {
        public:
            Ship(int weaponFrequency = 20, short repair = 3);
            
            void                setupCore(WarpSystem::Core *core);
            void                checkCore(void);
            Destination         getHome(void) const;
            Destination         getLocation(void) const;
            bool                move(int warp, Destination d);
            bool                move(int warp);
            bool                move(Destination d);
            bool                move();
            int                 getShield(void) const;
            void                setShield(int sheild);
            int                 getWeaponFrequency();
            void                setWeaponFrequency(int frequency);
            short               getRepair();
            void                setRepair(short repair);
        private:
            int                 _side;
            short               _maxWarp;
            WarpSystem::Core    *_core;
            Destination         _home;
            Destination         _location;
            int                 _shield;
            int                 _weaponFrequency;
            short               _repair;
    };
}
#endif //                       __BORG__