#ifndef                     __BORG__
    #define                 __BORG__

#include <iostream>
namespace                   Borg
{
    class                   Ship
    {
        public:
            Ship(void);
        private:
            int             _side;
            short           _maxWarp;
    };
}
#endif //                   __BORG__