#include "../test_include/test_Admiral.hpp"

namespace               Federation
{
    namespace           Starfleet
    {
        Admiral::Admiral(std::string name) :    _name(name)
        {
            std::cout   << "Admiral " << _name 
                        << " ready for action." << std::endl;           
        }

        std::string     Admiral::getName(void) const
        {
            return _name;
        }
    }
}