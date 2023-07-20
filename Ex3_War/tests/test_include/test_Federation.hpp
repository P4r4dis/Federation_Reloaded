#ifndef                                         __FEDERATION__
    #define                                     __FEDERATION__

#include <iostream>

#include "test_WarpSystem.hpp"
#include "test_Borg.hpp"
#include "Destination.hpp"

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
namespace                                       Federation
{
    namespace                                   Starfleet
    {
        class                                   Ship
        {
            public:
                Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0);
                Ship();
                int                             getLength(void) const;
                int                             getWidth(void) const;
                std::string                     getName(void) const;
                short                           getMaxWarp(void) const;
                Destination                     getHome(void) const;
                Destination                     getLocation(void) const;
                int                             getShield(void) const;
                int                             getTorpedo(void) const;

                void                            setShield(int sheild);
                void                            setTorpedo(int torpedo);


                void                            setupCore(WarpSystem::Core *core);
                void                            checkCore(void);
                void                            promote(Federation::Starfleet::Captain *captain);
                bool                            move(int warp, Destination d);
                bool                            move(int warp);
                bool                            move(Destination d);
                bool                            move(void);

                void                            fire(Borg::Ship *target);
                void                            fire(int torpedoes, Borg::Ship *target);

            private:
                int                             _length;
                int                             _width;
                std::string                     _name;
                short                           _maxWarp;
                WarpSystem::Core                *_core;
                Federation::Starfleet::Captain  *_captain;
                Destination                     _location;
                Destination                     _home;
                int                             _shield;
                int                             _photonTorpedo;
                
                
        };

        class                                   Captain
        {
            public:
                Captain(std::string name);

                std::string                     getName(void);
                int                             getAge(void);
                void                            setAge(int age);
            private:
                std::string                     _name;
                int                             _age;

        };

        class                                   Ensign
        {
            public:
                explicit Ensign(std::string name);
            private:
                const std::string               _name;
        };
    }

    class                                       Ship
    {
        public:
            Ship(int length, int width, std::string name);

            int                                 getLength(void) const;
            int                                 getWidth(void) const;
            std::string                         getName(void) const;

            void                                setupCore(WarpSystem::Core *core);
            void                                checkCore(void);
            WarpSystem::Core                    *getCore(void) const;
            Destination                         getHome(void) const;
            Destination                         getLocation(void) const;
            bool                                move(int warp, Destination d);
            bool                                move(int warp);
            bool                                move(Destination d);
            bool                                move();


        private:
            int                                 _length;
            int                                 _width;
            std::string                         _name;
            short                               _maxWarp;
            WarpSystem::Core                    *_core;
            Destination                         _home;
            Destination                         _location;
    };
}
#endif //                                       __FEDERATION__