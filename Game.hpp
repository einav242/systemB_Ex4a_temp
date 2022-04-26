#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;
namespace coup{
    class Game
    {
    private:
        /* data */
    public:
        Game();
        ~Game();
        static vector<string>players();
        static string turn();
        static string winner();
    };
    

    
}