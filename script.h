#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "BattleshipClasses.h"
#include "functions.h"

using namespace std;

// set to 5 temporarily to run the code
int totalRounds = 5;
string winningTeam;

// vector<shipHolder *> zShipTest;
// vector<shipHolder *> rShipTest;
// vector<crewHolder *> zCrewTest;
// vector<crewHolder *> rCrewTest;

// THE GAME LOOP
void runScript(const int &totalRounds, const string &winningTeam, vector<shipHolder *> &zShipTest, vector<shipHolder *> &rShipTest, vector<crewHolder *> &zCrewTest, vector<crewHolder *> &rCrewTest)
{
    cout << "The intergalactic battle begins! \n"
    << " Prepare your defences, ready your weapons and launch your attacks!" << endl;

    for (int round = 1; round <= totalRounds; round++)
    {
        cout << "=== " << "ROUND " << round << " ===" << "\n\n";

        // ship 2 uses (insertWEAPON)!
        // ship 1 HIT by ship 2 ! Dmg -20
        // or
        // ship 2 MISSES!

        // ship 1 uses (insertWEAPON)!
        // ship 2 HIT by ship 1 ! Dmg -30

        // ship x is destroyed!
        // Z crew 1 and crew 2 dies!

        // summary
        // Ship Z Total hit points : 100 
        // Ship R Total hit points : 120

        if (round == totalRounds)
        {
            cout << "=== GAME OVER ===" << "\n\n";

            cout << winningTeam << "WINS!" << endl;
        }
    }
}
