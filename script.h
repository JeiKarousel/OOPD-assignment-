#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "BattleshipClasses.h"
#include "functions.h"
#include "GameLogic.h"

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
    // DisplayFleet(zShip);
    cout << "--- ROGOASTUSKAN FLEET ---\n";
    // DisplayFleet(rShip);

    cout << "========================================" << endl;
    cout << "     BATTLE COMMENCING     " << endl;
    cout << "========================================" << endl;
    
    commenceBattle(zShip, rShip, winningTeam);

    cout << "========================================" << endl;
    cout << "              FINAL RESULT              " << endl;
    cout << "========================================" << endl;
    cout << "*** " << winningTeam << "WIN! ***" << endl;
}
