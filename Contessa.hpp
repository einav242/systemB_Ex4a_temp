#include <iostream>
#include "Player.hpp"
using namespace std;
namespace coup
{
    class Contessa:public Player
    {
    private:
        /* data */
    public:
        Contessa(Game const &g,string const &s);
        ~Contessa();
        void block(Player const &d);
    };
} // namespace name
