#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "BattleshipClasses.h"
#include "functions.h"

using namespace std;

int gameCounter = 1;
// set to 5 temporarily to run the code
int totalRounds = 5;

string winningTeam; 

// vector<shipHolder *> zShipTest;
// vector<shipHolder *> rShipTest;
// vector<crewHolder *> zCrewTest;
// vector<crewHolder *> rCrewTest;

// THE GAME LOOP
void runScript(int gameCounter, int totalRounds, vector<shipHolder*> &zShipTest, vector<shipHolder*> &rShipTest, vector<crewHolder *> &zCrewTest, vector<crewHolder *> &rCrewTest)
{
    for (int i = gameCounter; i<=totalRounds; i++){

        cout << "=== " << "ROUND " << i << " ==="<< "\n\n";

        if(gameCounter == i){

            cout << "The intergalactic battle begins! \n" << " Prepare your defences, ready your weapons and launch your attacks!" << endl;
        }










        if( i == totalRounds ){

            cout << "=== " << "GAME OVER" << i << " ==="<< "\n\n";

            cout << winningTeam << "WINS!"<< endl;
        }

    }

}
