#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "BattleshipClasses.h"
#include "functions.h"
#include "GameLogic.h"
#include <random>

using namespace std;

string winningTeam;

// THE GAME LOOP
void runScript(vector<Battleships *> &zShip, vector<Battleships *> &rShip)
{
    cout << "Loading data files...\n"
         << "========================================\n"
         << "    FLEET CONFIGURATION REPORT   \n"
         << "========================================\n";

    cout << "--- ZAPEZOID FLEET ---\n";
    DisplayZapezoidFleet(zShip);
    cout << "\n -- ROGOATUSKAN FLEET -- \n";
    DisplayRogoatuskanFleet(rShip);

    cout << "========================================" << endl;
    cout << "     BATTLE COMMENCING     " << endl;
    cout << "========================================" << endl;
    
    commenceBattle(zShip, rShip, winningTeam);

    cout << "========================================" << endl;
    cout << "              FINAL RESULT              " << endl;
    cout << "========================================" << endl;
    cout << "*** " << winningTeam << " WIN! ***" << endl;
}
