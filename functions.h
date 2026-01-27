#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include "BattleshipClasses.h"
#include <iomanip>
#include <random>

using namespace std;

bool isZapezoid = false;
bool isRogoatuskan = false;
bool isCrew = false;
bool isShips = false;

string trim(const string &str)
{
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

// Checks if the file is a CSV file
bool check_File_isCSV(const string filename)
{
    if (!(filename.substr(filename.size() - 4) == ".csv"))
    {
        cout << "Invalid type of file! " << endl;
        return 1;
    }
    return 0;
}

// Checks if the file is a Zapezoid, Rogoatuskan and if it is a ship or crew
bool check_Sides(const string filename)
{
    isZapezoid = false;
    isRogoatuskan = false;
    isCrew = false;
    isShips = false;

    if (filename.size() <= 4)
    {
        cout << "Invalid filename!" << filename << endl;
        return 1;
    }
    if (filename[0] == 'z')
    {
        isZapezoid = true;
    }
    else if (filename[0] == 'r')
    {
        isRogoatuskan = true;
    }
    else
    {
        cout << "Invalid name of file! Please specify type of ship/crew! " << endl;
        return 1;
    }

    if (filename.find("Ships") != string::npos)
    {
        isShips = true;
    }
    else if (filename.find("Crew") != string::npos)
    {
        isCrew = true;
    }
    else
    {
        cout << "Invalid filename!" << filename << endl;
        return 1;
    }
    return 0;
}

// EXAMPLE FILE CONTENT:
// Z-S-001,Guerriero,Name1
// Z-S-002,Medio,Name2
// Z-S-003,Corazzata,Name3

// R-S-001,Jager,Name1
// R-S-002,Kreuzer,Name2
// R-S-003,Fregatte,Name3

// ALL ZAPEZOID
void Read_zShipFromFile(ifstream &inFile1, vector<Battleships *> &zShip)
{
    string SHIP_id, SHIP_name, SHIP_type, content;

    // getting one line of content from the fstream eg: "Z-S-001,Guerriero,Name1" through a loop
    // Will fix ships later
    while (getline(inFile1, content, '\n'))
    {
        stringstream stream2(content);

        // get id, shiptype then name
        getline(stream2, SHIP_id, ',');
        getline(stream2, SHIP_type, ',');
        getline(stream2, SHIP_name);

        SHIP_type = trim(SHIP_type);

        if (SHIP_type == "Guerriero")
        {
            zShip.push_back(new Guerriero(123, SHIP_id, SHIP_name));
        }
        else if (SHIP_type == "Medio")
        {
            zShip.push_back(new Medio(214, SHIP_id, SHIP_name));
        }
        else if (SHIP_type == "Corazzata")
        {
            zShip.push_back(new Corazzata(1031, SHIP_id, SHIP_name));
        }
        else
        {
            cout << "Ship type not found! In file line " << content << "!" << endl;
            continue;
        }
    }
}

// ALL ROGOATUSKAN
void Read_rShipFromFile(ifstream &inFile1, vector<Battleships *> &rShipTest)
{
    string SHIP_id, SHIP_name, SHIP_type, content;

    // getting one line of content from the fstream eg: "R-S-001,Jager,Name1" through a loop
    while (getline(inFile1, content, '\n'))
    {
        stringstream stream2(content);

        // get id, shiptype then name
        getline(stream2, SHIP_id, ',');
        getline(stream2, SHIP_type, ',');
        getline(stream2, SHIP_name);

        SHIP_id = trim(SHIP_id);
        SHIP_name = trim(SHIP_name);
        SHIP_type = trim(SHIP_type);

        // create an object depending on ship type
        if (SHIP_type == "Jager")
        {
            rShipTest.push_back(new Jager(112, SHIP_id, SHIP_name));
        }
        else if (SHIP_type == "Kreuzer")
        {
            rShipTest.push_back(new Kreuzer(212, SHIP_id, SHIP_name));
        }
        else if (SHIP_type == "Fregatte")
        {
            rShipTest.push_back(new Fregatte(1143, SHIP_id, SHIP_name));
        }
        else
        {
            cout << "Ship type not found! In file line " << content << "!" << endl;
            continue;
        }
    }
}

// EXAMPLE FILE CONTENT:
// R-C-001,Allen,Pilot
// R-C-002,json,Gunner
// R-C-003,Imr,TorpedoHandler
// R-C-004,Riduan,Gunner
// R-C-005,Qi Yang,Pilot

// ALL CREWS (vector determines what ship they are assigned to) (can either be r or z)
void Read_CrewFromFile(ifstream &inFile1, vector<crewHolder *> &CrewVector)
{
    string CREW_id, CREW_name, CREW_type, content;

    // getting one line of content from the fstream eg: "R-C-001,Allen,Pilot" through a loop
    while (getline(inFile1, content))
    {
        if (content.empty())
        {
            continue;
        }

        stringstream stream2(content);

        // get id, crewtype then name
        getline(stream2, CREW_id, ',');
        getline(stream2, CREW_name, ',');
        getline(stream2, CREW_type);

        CREW_id = trim(CREW_id);
        CREW_name = trim(CREW_name);
        CREW_type = trim(CREW_type);

        crewHolder *c = nullptr;

        // create an object depending on crew type
        if (CREW_type == "Pilot")
        {
            CrewVector.push_back(new pilot(CREW_id, CREW_name));
        }
        else if (CREW_type == "Gunner")
        {
            CrewVector.push_back(new gunner(CREW_id, CREW_name));
        }
        else if (CREW_type == "TorpedoHandler")
        {
            CrewVector.push_back(new torpedohandler(CREW_id, CREW_name));
        }
        else
        {
            if (CREW_id.find("source") == string::npos)
            {
                cout << "Unknown crew type: [" << CREW_type << "] in line: " << content << endl;
            }
            continue;
        }
    }
}

// Function to assign crews to ships
void assign_Crew_to_Ship(vector<crewHolder *> &crew, vector<Battleships *> &ships)
{
    vector<pilot *> availablePilots;
    vector<gunner *> availableGunners;
    vector<torpedohandler *> availableTorpedoHandlers;

    for (crewHolder *c : crew)
    {
        if (pilot *p = dynamic_cast<pilot *>(c))
        {
            availablePilots.push_back(p);
        }
        else if (gunner *g = dynamic_cast<gunner *>(c))
        {
            availableGunners.push_back(g);
        }
        else if (torpedohandler *t = dynamic_cast<torpedohandler *>(c))
        {
            availableTorpedoHandlers.push_back(t);
        }
    }

    int totalPilots = availablePilots.size();

    for (Battleships *ship : ships)
    {
        if (!availablePilots.empty() && ship->currentPilots < ship->requiredPilots)
        {
            pilot *loadingCrew = availablePilots.back();
            ship->assignPilot(loadingCrew);
            availablePilots.pop_back();
        }
    }

    bool pilotAssigned = true;
    while (pilotAssigned && !availablePilots.empty())
    {
        pilotAssigned = false;
        for (Battleships *ship : ships)
        {
            while (!availablePilots.empty() && ship->currentPilots < ship->requiredPilots)
            {
                pilot *loadingCrew = availablePilots.back();
                ship->assignPilot(loadingCrew);
                availablePilots.pop_back();
                pilotAssigned = true;
            }

            while (!availableGunners.empty() && ship->currentGunners < ship->requiredGunners)
            {
                gunner *loadingCrew = availableGunners.back();
                ship->assignGunner(loadingCrew);
                availableGunners.pop_back();
            }
            
            while (!availableTorpedoHandlers.empty() && ship->currentTorpedoHandlers < ship->requiredTorpedoHandlers)
            {
                torpedohandler *loadingCrew = availableTorpedoHandlers.back();
                ship->assignTorpedoHandler(loadingCrew);
                availableTorpedoHandlers.pop_back();
            }
            
        }
    }
}

// DISPLAY Zapezoid fleet 
void DisplayZapezoidFleet(vector<Battleships*> zShip)
{
    for (int i = 0; i < zShip.size(); i++){
        cout << "[Z-S-" << setw(3) << setfill('0') << i + 1 << "] "
             << left << setw(10) << setfill(' ') << zShip[i]->getShipName()
             << "(" << zShip[i]->getShipType() << ")" << endl;

        cout << " HP: " << zShip[i]->getHealthPoints()
             << "/" << zShip[i]->getHealthPoints() << endl;

        for (pilot* p : zShip[i]->getPilots()){
            cout << " Pilots (" << zShip[i]->currentPilots << "): "
                 << p->getName() << endl;
        }
        for (gunner* g : zShip[i]->getGunners()){
            cout << " Gunners (" << zShip[i]->currentGunners << "): "
                 << g->getName() << endl;
        }
        for (torpedohandler* t : zShip[i]->getTorpedoHandlers()){
            cout << " Torpedo Handlers (" << zShip[i]->currentTorpedoHandlers << "): "
                 << t->getName() << endl;
        }
        cout << "--------------------------------------------------" << endl;
    }
}


// DISPLAY Rogoatuskan fleet
void DisplayRogoatuskanFleet(vector<Battleships*> rShip)
{
    for (int i = 0; i < rShip.size(); i++){
        cout << "[R-S-" << setw(3) << setfill('0') << i + 1 << "] "
             << left << setw(10) << setfill(' ') << rShip[i]->getShipName()
             << "(" << rShip[i]->getShipType() << ")" << endl;

        cout << " HP: " << rShip[i]->getHealthPoints()
             << "/" << rShip[i]->getHealthPoints() << endl;

        for (pilot* p : rShip[i]->getPilots()){
            cout << " Pilots (" << rShip[i]->currentPilots << "): "
                 << p->getName() << endl;
        }
        for (gunner* g : rShip[i]->getGunners()){
            cout << " Gunners (" << rShip[i]->currentGunners << "): "
                 << g->getName() << endl;
        }
        for (torpedohandler* t : rShip[i]->getTorpedoHandlers()){
            cout << " Torpedo Handlers (" << rShip[i]->currentTorpedoHandlers << "): "
                 << t->getName() << endl;
        }

        cout << "--------------------------------------------------" << endl;
    }
}


#endif