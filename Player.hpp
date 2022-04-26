#pragma once
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;
namespace coup
{
    class Player
    {
    public:
        ~Player();
        void income();
        void foreign_aid();
        void coup(Player const &p);
        static string role();
        static int coins();
    };

}
