#include <iostream>
#include <stdexcept>
#include <string>
#include"Player.hpp"
using namespace std;
namespace coup
{
    class Captain:public Player
    {
    private:
        /* data */
    public:
        Captain(Game const &g,string const &s);
        void steal(Player const &p);
        ~Captain();
        void block(Player const &d);
    };
} // namespace coup
