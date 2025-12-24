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
#include <vector>
#include "BattleshipClasses.h"
#include "functions.h"

using namespace std;

bool isZapezoid = false;
bool isRogoatuskan = false;
bool isCrew = false;
bool isShips = false;


int main(int argc, char *argv[])
{
    // XyloTT9L zShips1.csv zCrew1.csv rShips1.csv rCrew1.csv
    // check if every file has .csv, and therefore valid input

    vector<shipHolder *> zShipTest;
    vector<shipHolder *> sShipTest;
    vector<crewHolder *> zCrewTest;
    vector<crewHolder *> sCrewTest;

    string userInput, content;
    string SHIP_id, SHIP_name, SHIP_type;
    string CREW_id, CREW_name, CREW_type;

    cout << "Battleship time! Enter the filenames: " << endl;

    // make sure there are 5 arguments
    if (argc != 5)
    {
        cout << "PLease follow the format of NameTutorialGroup file1.csv file2.csv file3.csv file4.csv " << endl;
        return 1;
    }

    // go through every string in argv, and check what type of file it is, then assign the objects
    for (int i = 1; i < argc; i++)
    {
        userInput = argv[i];

        // check if it is a csv file
        check_File_isCSV(userInput);
        // check whether it is a Rogoatuskan or a Zapezoids type, and whether it is a crew or ship
        check_Sides(userInput);

        ifstream inFile1;
        inFile1.open(userInput);

        if (!inFile1.is_open())
        {
            cout << "File not found! " << endl;
            return 1;
        }

        // 1SR, Jager, Name1
        // 2SR, Kreuzer, Name2
        // 3SR, Fregatte, Name3

        // possibilities:
        //  z or s, then in, check if c or s
        if (isZapezoid)
        {
            // all zaps
            if (isShips)
            {
                // where i will be putting the logic
                // AssignShips();

                // getting one line from the fstream (line from file content)
                while (getline(inFile1, content, '\n'))
                {
                    stringstream stream2(content);
                    // get id, shiptype then name
                    getline(stream2, SHIP_id, ',');
                    getline(stream2, SHIP_type, ',');
                    getline(stream2, SHIP_name);

                    shipHolder *s;

                    if (SHIP_type == "Guerriero")
                    {
                        s = new Guerriero(SHIP_id, SHIP_name);
                    }
                    else if (SHIP_type == "Medio")
                    {
                        s = new Medio(SHIP_id, SHIP_name);
                    }
                    else if (SHIP_type == "Corazzata")
                    {
                        s = new Corazzata(SHIP_id, SHIP_name);
                    }
                    else
                    {
                        cout << "Ship type not found! In file name " << userInput << "!" << endl;
                        return 1;
                    }

                    zShipTest.push_back(s);
                }

                inFile1.close();
            }
        }

        if (isCrew)
        {
            // 3CZ, chipi, torpedo handler
            // 4CZ, lisa, pilot
            // 5CZ, gato, gunner

            // getting one line from the fstream (line from file content)
            while (getline(inFile1, content, '\n'))
            {
                stringstream stream2(content);
                // get id, shiptype then name
                getline(stream2, CREW_id, ',');
                getline(stream2, CREW_type, ',');
                getline(stream2, CREW_name);

                crewHolder *c;

                if (CREW_type == "pilot")
                {

                    c = new pilot(CREW_id, CREW_name);
                }
                else if (CREW_type == "gunner")
                {

                    c = new gunner(CREW_id, CREW_name);
                }
                else if (CREW_type == "torpedohandler")
                {

                    c = new torpedohandler(CREW_id, CREW_name);
                }
                else
                {
                    cout << "Crew type not found! In file name " << userInput << "!" << endl;
                    return 1;
                }

                zCrewTest.push_back(c);
            }
        }

        inFile1.close();
    }

    if(isRogoatuskan){

        if(isShips){}

        if(isCrew){}
    }

    //WHERE WE SHOULD DELETE THE OBJECTS

    return 0;
}
