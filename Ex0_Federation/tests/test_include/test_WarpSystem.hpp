#ifndef                     __WARPSYSTEM__
    #define                 __WARPSYSTEM__

namespace                   WarpSystem
{
    class                   QuantumReactor
    {
        public:
            QuantumReactor(void);

            bool            isStable(void);
            void            setStability(bool stability);
        private:
            bool            _stability;
    };
}
#endif //                   __WARPSYSTEM__