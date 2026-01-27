// Australia TT3L
// Elsa Zara Binti Fakhurrazi
// Muhammad Yusuf Bin Riduan
// Wan Wei Siang
// Syed Zaki Husain Wafa

// TO REMOVE:
// In addition to normal things like explaining the purpose of the code, etc. also comment as to who wrote a particular
// piece of code, method, or even part of a method, if more than one person made changes to a method. If you did
// pair programming for a particular piece of code, write both names.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include "BattleshipClasses.h"
#include "functions.h"
#include "script.h"
#include "GameLogic.h"
#include <random>
using namespace std;

// setting the seed and general bool
random_device rnd;
mt19937 gen(rnd());

bool isZapezoid = false;
bool isRogoatuskan = false;
bool isCrew = false;
bool isShips = false;

// main handled by: (ELSA ZARA BINTI FAKHURRAZI)
int main(int argc, char *argv[])
{
    // Initializing the vectors and variables used
    vector<Battleships *> zShip;
    vector<Battleships *> rShip;
    vector<crewHolder *> zCrew;
    vector<crewHolder *> rCrew;

    string userInput;
    // Example input: 
    //AustraliaTT3L zShips1.csv zCrew1.csv rShips1.csv rCrew1.csv
    //AustraliaTT3L zShips2.csv zCrew2.csv rShips2.csv rCrew2.csv
    //AustraliaTT3L zShips3.csv zCrew3.csv rShips3.csv rCrew3.csv
    cout << "Battleship time!" << endl << endl; 
    
    // Makes sure there are 5 arguments
    if (argc != 5)
    {
        cout << "Please follow the format of NameTutorialGroup file1.csv file2.csv file3.csv file4.csv " << endl;
        return 1;
    }

    // Goes through every string in argv, eg: "zShips1.csv" at arg[1] and check filetype, then create object
    for (int i = 1; i < argc; i++)
    {
        userInput = argv[i];

        // Check whether it is a csv file
        check_File_isCSV(userInput);
        // Check whether it is z or s, and ship or crew, then update bool
        check_Sides(userInput);

        ifstream inFile1;
        inFile1.open(userInput);

        if (!inFile1.is_open())
        {
            cout << "File not found! " << endl;
            return 1;
        }

        // Zapezoid object creation
        if (isZapezoid)
        {
            if (isShips)
            {
                Read_zShipFromFile(inFile1, zShip);
                inFile1.close();
            }

            if (isCrew)
            {
               Read_CrewFromFile(inFile1, zCrew);
               inFile1.close();
            }
        }

        // Rogoatuskan object creation
        if (isRogoatuskan)
        {
            if (isShips)
            {
                Read_rShipFromFile(inFile1, rShip);
                inFile1.close();
            }

            if (isCrew)
            {
               Read_CrewFromFile(inFile1, rCrew);
               inFile1.close();
            }
        }
    }

    // Assigns every crew to each ship specific to type 
    assign_Crew_to_Ship(zCrew, zShip);
    assign_Crew_to_Ship(rCrew, rShip);

    // Sets the booleans needed to run game loop
    setBool(zShip);
    setBool(rShip);

    // Start the battle simulation
    runScript(zShip, rShip);

    // Deletes all pointers that are made in the heap
    for(Battleships* z:  zShip ){
        delete z;
    }
    for(Battleships* r:  rShip ){
        delete r;
    }
      for(crewHolder* c:  zCrew){
        delete c;
    }
    for(crewHolder* c:  rCrew){
        delete c;
    }
    return 0;
}