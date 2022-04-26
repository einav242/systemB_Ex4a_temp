#include <iostream>
#include <stdexcept>
#include <string>
#include"Player.hpp"
using namespace std;
namespace coup{
    class Duke :public Player
    {
    private:
        /* data */
    public:
        Duke(Game const& g,string const& s);
        void block(Player const &d);
        void tax();
        ~Duke();
    };
}