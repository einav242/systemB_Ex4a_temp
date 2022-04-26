#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

#include <string>
using namespace std;

TEST_CASE("Good input")
{
   Game game_1{};
   Duke duke{game_1, "Moshe"};
   Assassin assassin{game_1, "Yossi"};
   Ambassador ambassador{game_1, "Meirav"};
   Captain captain{game_1, "Reut"};
   Contessa contessa{game_1, "Gilad"};
   vector<string> t1 = {"Moshe", "Yossi", "Meirav", "Reut", "Gilad"};
   for (unsigned int i = 0; i < 5; i++)
   {
      CHECK(game_1.players()[i] == t1[i]);
   }
   CHECK(game_1.turn() == "Moshe");
   duke.tax();
   CHECK(duke.coins() == 3);
   CHECK(game_1.turn() == "Yossi");
   assassin.income();
   CHECK(assassin.coins() == 1);
   CHECK(game_1.turn() == "Meirav");
   ambassador.transfer(duke, assassin);
   CHECK(duke.coins() == 2);
   CHECK(assassin.coins() == 2);
   CHECK(game_1.turn() == "Reut");
   captain.steal(duke);
   CHECK(duke.coins() == 0);
   CHECK(captain.coins() == 2);
   CHECK(game_1.turn() == "Gilad");
   contessa.foreign_aid();
   CHECK(contessa.coins() == 2);

   CHECK(game_1.turn() == "Moshe");
   duke.tax();
   CHECK(duke.coins() == 3);
   CHECK(game_1.turn() == "Yossi");
   assassin.foreign_aid();
   CHECK(assassin.coins() == 4);
   CHECK(game_1.turn() == "Meirav");
   ambassador.transfer(duke, contessa);
   CHECK(duke.coins() == 1);
   CHECK(contessa.coins() == 4);
   CHECK(ambassador.coins() == 0);
   CHECK(game_1.turn() == "Reut");
   captain.foreign_aid();
   duke.block(captain);
   CHECK(captain.coins() == 2);
   CHECK(game_1.turn() == "Gilad");
   contessa.foreign_aid();
   CHECK(contessa.coins() == 6);

   CHECK(game_1.turn() == "Moshe");
   duke.income();
   CHECK(duke.coins() == 2);
   CHECK(game_1.turn() == "Yossi");
   assassin.coup(duke);
   CHECK(assassin.coins() == 1);
   vector<string> t2 = {"Yossi", "Meirav", "Reut", "Gilad"};
   for (unsigned int i = 0; i < 4; i++)
   {
      CHECK(game_1.players()[i] == t2[i]);
   }
   CHECK(game_1.turn() == "Meirav");
   ambassador.transfer(captain, contessa);
   CHECK(ambassador.coins() == 0);
   CHECK(captain.coins() == 0);
   CHECK(contessa.coins() == 8);
   CHECK(game_1.turn() == "Reut");
   captain.foreign_aid();
   CHECK(captain.coins() == 2);
   CHECK(game_1.turn() == "Gilad");
   contessa.coup(captain);
   CHECK(contessa.coins() == 1);
   vector<string> t3 = {"Yossi", "Meirav", "Gilad"};
   for (unsigned int i = 0; i < 3; i++)
   {
      CHECK(game_1.players()[i] == t3[i]);
   }

   CHECK(game_1.turn() == "Yossi");
   assassin.foreign_aid();
   CHECK(assassin.coins() == 3);
   CHECK(game_1.turn() == "Meirav");
   ambassador.transfer(contessa, assassin);
   CHECK(assassin.coins() == 4);
   CHECK(contessa.coins() == 0);
   CHECK(ambassador.coins() == 0);
   CHECK(game_1.turn() == "Gilad");
   contessa.income();
   CHECK(contessa.coins() == 1);

   CHECK(game_1.turn() == "Yossi");
   assassin.coup(contessa);
   CHECK(assassin.coins() == 1);
   vector<string> t4 = {"Yossi", "Meirav"};
   for (unsigned int i = 0; i < 2; i++)
   {
      CHECK(game_1.players()[i] == t4[i]);
   }
   CHECK(game_1.turn() == "Meirav");
   ambassador.income();
   CHECK(ambassador.coins() == 1);
   CHECK(game_1.turn() == "Yossi");
   assassin.foreign_aid();
   CHECK(assassin.coins() == 3);
   CHECK(game_1.turn() == "Meirav");
   ambassador.income();
   CHECK(ambassador.coins() == 2);

   CHECK(game_1.turn() == "Yossi");
   assassin.coup(ambassador);
   vector<string> t5 = {"Yossi"};
   for (unsigned int i = 0; i < 1; i++)
   {
      CHECK(game_1.players()[i] == t5[i]);
   }
   CHECK(assassin.coins() == 0);
   CHECK(game_1.winner() == "Yossi");
}

TEST_CASE("Bad use of operators")
{
   Game game_2{};
   Duke duke{game_2, "einav"};
   Assassin assassin{game_2, "bar"};
   Ambassador ambassador{game_2, "gal"};
   Captain captain{game_2, "tal"};
   Contessa contessa{game_2, "stav"};
   duke.foreign_aid();
   assassin.income();
   CHECK_THROWS(ambassador.block(duke));
   CHECK_THROWS(captain.block(duke));
   CHECK_THROWS(contessa.block(duke));
   CHECK_THROWS(duke.coup(captain));
   CHECK_THROWS(assassin.coup(captain));
   CHECK_THROWS(ambassador.coup(captain));
   CHECK_THROWS(captain.coup(duke));
   CHECK_THROWS(contessa.coup(captain));
   CHECK_THROWS(game_2.winner());
   CHECK_THROWS(captain.income());
   CHECK_THROWS(contessa.income());

}