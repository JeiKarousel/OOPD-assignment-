// Xylo TT3L
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

// setting the seed
random_device rnd;
mt19937 gen(rnd());

int main(int argc, char *argv[])
{
    // initializing the vectors and variables used
    vector<Battleships *> zShip;
    vector<Battleships *> rShip;
    vector<crewHolder *> zCrew;
    vector<crewHolder *> rCrew;

    string userInput;

    cout << "Battleship time!" << endl << endl;
    // Example input: AustraliaTT3L zShips1.csv zCrew1.csv rShips1.csv rCrew1.csv
    //AustraliaTT3L zShips2.csv zCrew2.csv rShips2.csv rCrew2.csv

    // make sure there are 5 arguments
    if (argc != 5)
    {
        cout << "Please follow the format of NameTutorialGroup file1.csv file2.csv file3.csv file4.csv " << endl;
        return 1;
    }

    // go through every string in argv, eg: "zShips1.csv" at arg[1] and check filetype, then create object
    for (int i = 1; i < argc; i++)
    {
        userInput = argv[i];

        // check if it is a csv file
        check_File_isCSV(userInput);
        // check whether it is z or s, and ship or crew, then update bool
        check_Sides(userInput);

        ifstream inFile1;
        inFile1.open(userInput);

        if (!inFile1.is_open())
        {
            cout << "File not found! " << endl;
            return 1;
        }

        // ZAPEZOID OBJECT CREATION
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

        // ROGOATUSKAN OBJECT CREATION
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

    assign_Crew_to_Ship(zCrew, zShip);
    assign_Crew_to_Ship(rCrew, rShip);

    SetBool(zShip);
    SetBool(rShip);

    // start the battle simulation
    runScript(zShip, rShip);
    return 0;
}