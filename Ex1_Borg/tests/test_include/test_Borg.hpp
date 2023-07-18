#ifndef                         __BORG__
    #define                     __BORG__

#include <iostream>
#include "test_WarpSystem.hpp"
namespace                       Borg
{
    class                       Ship
    {
        public:
            Ship(void);
            void                setupCore(WarpSystem::Core *core);
        private:
            int                 _side;
            short               _maxWarp;
            WarpSystem::Core    *_core;
    };
}
#endif //                       __BORG__