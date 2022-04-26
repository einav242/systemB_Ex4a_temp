#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include"Player.hpp"
using namespace std;
namespace coup
{
class Ambassador:public Player
{
public:
Ambassador(Game const &g,string const &s);
~Ambassador();
void transfer(Player const &p1, Player const &p2);
void block(Player const &d);
};
} 