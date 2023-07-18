#ifndef                             __FEDERATION__
    #define                         __FEDERATION__

#include <iostream>

#include "WarpSystem.hpp"

namespace                           Federation
{
    namespace                       Starfleet
    {
        class                       Ship
        {
            public:
                Ship(int length, int width, std::string name, short maxWarp);

                int                 getLength(void) const;
                int                 getWidth(void) const;
                std::string         getName(void) const;
                short               getMaxWarp(void) const;

                void                setupCore(WarpSystem::Core *core);
                void                checkCore(void);
            private:
                int                 _length;
                int                 _width;
                std::string         _name;
                short               _maxWarp;
                WarpSystem::Core    *_core;
        };
    }

    class                           Ship
    {
        public:
            Ship(int length, int width, std::string name);

            int                     getLength(void) const;
            int                     getWidth(void) const;
            std::string             getName(void) const;

            void                    setupCore(WarpSystem::Core *core);
            void                    checkCore(void);

        private:
            int                     _length;
            int                     _width;
            std::string             _name;
            WarpSystem::Core        *_core;
    };
}
#endif //                           __FEDERATION__