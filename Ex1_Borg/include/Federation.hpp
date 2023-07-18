#ifndef                             __FEDERATION__
    #define                         __FEDERATION__

#include <iostream>

#include "WarpSystem.hpp"
namespace Federation
{
    namespace Starfleet
    {
        class Ship;
        class Captain;
        class Ensign;
    }
    class Ship;
}
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

                void                promote(Federation::Starfleet::Captain *captain);
            private:
                int                             _length;
                int                             _width;
                std::string                     _name;
                short                           _maxWarp;
                WarpSystem::Core                *_core;
                Federation::Starfleet::Captain  *_captain;
        };

        class                       Captain
        {
            public:
                Captain(std::string name);

                std::string         getName(void);
                int                 getAge(void);
                void                setAge(int age);
            private:
                std::string         _name;
                int                 _age;

        };

        class                       Ensign
        {
            public:
                explicit Ensign(std::string name);
            private:
                const std::string         _name;
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
            short                   _maxWarp;
            WarpSystem::Core        *_core;
    };
}
#endif //                           __FEDERATION__