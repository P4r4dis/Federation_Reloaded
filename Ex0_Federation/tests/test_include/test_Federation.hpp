#ifndef                         __FEDERATION__
    #define                     __FEDERATION__

#include <iostream>

namespace                       Federation
{
    namespace                   Starfleet
    {
        class                   Ship
        {
            public:
                Ship(int length, int width, std::string name, short maxWarp);
                Ship(int length, int width, std::string name);

                int             getLength(void) const;
                int             getWidth(void) const;
                std::string     getName(void) const;
                short           getMaxWarp(void) const;
            private:
                int             _length;
                int             _width;
                std::string     _name;
                short           _maxWarp;
        };
    }

    class                       Ship
    {
        public:
            Ship(int length, int width, std::string name);

            int                 getLength(void) const;
            int                 getWidth(void) const;
            std::string         getName(void) const;
        private:
            int                 _length;
            int                 _width;
            std::string         _name;
    };
}
#endif //                       __FEDERATION__