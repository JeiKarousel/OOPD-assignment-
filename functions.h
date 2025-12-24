#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool isZapezoid = false;
bool isRogoatuskan = false;
bool isCrew = false;
bool isShips = false;

// Checks if the file is a CSV file
bool check_File_isCSV(const string filename)
{
    if (!(filename.substr(filename.size() - 4) == ".csv"))
    {
        cout << "Invalid type of file! " << endl;
        return 1;
    }
}

// Checks if the file is a Zapezoid, Rogoatuskan and if it is a ship or crew
bool check_Sides(const string filename)
{
    if (filename.size() <= 4)
    {
        cout << "Invalid filename!" << endl;
    }

    if (filename[0] == 'z')
    {
        return isZapezoid = true;
    }
    else if (filename[0] == 'r')
    {
        return isRogoatuskan = true;
    }
    else
    {
        cout << "Invalid name of file! Please specify type of ship/crew! " << endl;
        return 1;
    }

    if (filename.substr(1, (filename.size() - 4)) == "Ships" || filename.substr(1, (filename.size() - 5)) == "Ships")
    {
        isShips = true;
    }
    else if (filename.substr(1, (filename.size() - 4)) == "Crew" || filename.substr(1, (filename.size() - 5)) == "Crew")
    {
        isCrew = true;
    }
    else
    {
        cout << "Invalid filename!" << endl;
        return 1;
    }
}

// EXAMPLE FILE CONTENT:
// 1SR, Jager, Name1
// 2SR, Kreuzer, Name2
// 3SR, Fregatte, Name3

// ALL ZAPEZOID
void Read_zShipFromFile(ifstream &inFile1, vector<shipHolder *> &zShipTest)
{
    string SHIP_id, SHIP_name, SHIP_type, content;

    // getting one line of content from the fstream eg: "1SR, Jager, Name1" through a loop
    while (getline(inFile1, content, '\n'))
    {
        stringstream stream2(content);

        // get id, shiptype then name
        getline(stream2, SHIP_id, ',');
        getline(stream2, SHIP_type, ',');
        getline(stream2, SHIP_name);

        shipHolder *s = nullptr;

        // create an object depending on ship type
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
            cout << "Ship type not found! In file line " << content << "!" << endl;
            continue;
        }

        // push the pointer into the respective vectors
        zShipTest.push_back(s);
    }
}
// EXAMPLE FILE CONTENT:
// 3CZ, chipi, torpedo handler
// 4CZ, lisa, pilot
// 5CZ, gato, gunner

// ALL ROGOATUSKAN 
void Read_rShipFromFile(ifstream &inFile1, vector<shipHolder *> &rShipTest)
{
    string SHIP_id, SHIP_name, SHIP_type, content;

    // getting one line of content from the fstream eg: "1SR, Jager, Name1" through a loop
    while (getline(inFile1, content, '\n'))
    {
        stringstream stream2(content);

        // get id, shiptype then name
        getline(stream2, SHIP_id, ',');
        getline(stream2, SHIP_type, ',');
        getline(stream2, SHIP_name);

        shipHolder *s = nullptr;

        // create an object depending on ship type
        if (SHIP_type == "Jager")
        {
            s = new Jager(SHIP_id, SHIP_name);
        }
        else if (SHIP_type == "Kreuzer")
        {
            s = new Kreuzer(SHIP_id, SHIP_name);
        }
        else if (SHIP_type == "Fregatte")
        {
            s = new Fregatte(SHIP_id, SHIP_name);
        }
        else
        {
            cout << "Ship type not found! In file line " << content << "!" << endl;
            continue;
        }

        // push the pointer into the respective vectors
        rShipTest.push_back(s);
    }
}

// ALL CREWS (vector determines what ship they are assigned to) (can either be r or z)
void Read_CrewFromFile(ifstream &inFile1, vector<crewHolder *> &CrewVector)
{
    string CREW_id, CREW_name, CREW_type, content;

    // getting one line of content from the fstream eg: "1SR, Jager, Name1" through a loop
    while (getline(inFile1, content, '\n'))
    {
        stringstream stream2(content);

        // get id, shiptype then name
        getline(stream2, CREW_id, ',');
        getline(stream2, CREW_type, ',');
        getline(stream2, CREW_name);

        crewHolder *c = nullptr;

        // create an object depending on crew type
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
            cout << "Crew type not found! In file name " << content << "!" << endl;
            continue;
        }

        // push the pointer into the respective vectors
        CrewVector.push_back(c);
    }
}

