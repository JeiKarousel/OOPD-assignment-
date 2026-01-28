#ifndef GAMELOGIC_H
#define GAMELOGIC_H

// Australia TT3L
// Elsa Zara Binti Fakhurrazi
// Muhammad Yusuf Bin Riduan
// Wan Wei Siang
// Syed Zaki Husain Wafa

#include <iostream>
#include <vector>
#include <iomanip>
#include "BattleshipClasses.h"
#include "functions.h"
#include <random>
using namespace std;
extern mt19937 gen;

// Rolls a random number (ELSA ZARA BINTI FAKHURRAZI)
int roll(int min, int max)
{
    uniform_int_distribution<> dist(min, max);
    int randomNum = dist(gen);
    return randomNum;
}

// Function to set bool (ELSA ZARA BINTI FAKHURRAZI)
void setBool(vector<Battleships *> &ShipVector)
{
    for (Battleships *s : ShipVector)
    {
        s->checkOperationStatus();
    }
}

// Displays each time a ship attacks (ELSA ZARA BINTI FAKHURRAZI) & (MUHAMMAD YUSUF BIN RIDUAN)
void displayHit_Miss(bool hit, Battleships *Ship, crewHolder *Crew, string weapon, Battleships *enemyShip, int damage)
{
    // safety check for nullptr crew
    string crewName = (Crew != nullptr) ? Crew->getName() : "Unknown Pilot Crew";
    cout << Ship->getShipType() << " " << Ship->getShipName() << "'s " << weapon << " crew " << crewName << " fires at " << enemyShip->getShipType() << " " << enemyShip->getShipName() << "...";
    if (hit)
    {
        cout << "HIT! " << "(" << damage << "dmg)" << endl;
    }
    else
    {
        cout << "MISS." << endl;
    }
}

// Rolls to determine whether ship can successfully attack enemy ship (WAN WEI SIANG) & (ELSA ZARA BINTI FAKHURRAZI) 
bool Roll_Hit_Miss(Battleships *Target, string weapon)
{
    // From values 0 to 100
    int value = roll(0, 99);

    if (weapon == "Cannon") {
        return (value < Target->getHitByCannon());
    } 
    else if (weapon == "Torpedo") {
        return (value < Target->getHitByTorpedo());
    }
    return false;
}

// Chooses an enemy ship to be attacked (ELSA ZARA BINTI FAKHURRAZI) 
Battleships *chooseEnemyShip(vector<Battleships *> enemyShip)
{
    vector<Battleships *> validTarget;
    for (Battleships *e : enemyShip)
    {
        if (e->canOperate)
        {
            validTarget.push_back(e);
        }
    }
    // Preventing roll(0,-1)
    if(validTarget.empty()){
        return nullptr;
    }

    // Get index of random enemy ship
    int index = roll(0, (validTarget.size() - 1));
    return validTarget[index];
}

// Sequence of logic for a ship to attack an enemy ship (ELSA ZARA BINTI FAKHURRAZI) 
void fightSequence(crewHolder *crew, Battleships *s, bool &hit, vector<Battleships *> &enemyShip, string weapon)
{
    // Choose an enemy ship
    Battleships *targetShip = chooseEnemyShip(enemyShip);

    if (targetShip == nullptr)
        return;
    
    // Roll to see if the weapon successfully hit or missed the enemy ship
    hit = Roll_Hit_Miss(targetShip, weapon);

    if (hit)
    {
        // Displays successful attack 
        displayHit_Miss(hit, s, crew, weapon, targetShip, (weapon == "Cannon") ? s->returnCannonWeapon().power : s->returnTorpedoWeapon().power);
        targetShip->totalDamageTaken((weapon == "Cannon") ? s->returnCannonWeapon().power : s->returnTorpedoWeapon().power);
    }
    else
    {
        // Displays unsuccessful attack 
        displayHit_Miss(hit, s, crew, weapon, targetShip, (weapon == "Cannon") ? s->returnCannonWeapon().power : s->returnTorpedoWeapon().power);
    }
}

// Shows the fleet status report after every round (MUHAMMAD YUSUF BIN RIDUAN)
void fleetReport(vector<Battleships *> &ships, string teamName, string idPrefix) {
   
    cout << teamName << ":"<< endl;
    for (size_t i = 0; i < ships.size(); i++) {
        cout << " [" << idPrefix << setw(3) << setfill('0') << (i + 1) << "] ";

        cout << ships[i]->getShipType() << " " << ships[i]->getShipName() << " ";

        if (ships[i]->canOperate) {
            cout << "(" << ships[i]->getHealthPoints() << "/" << ships[i]->getMaxHealth() << ")";
        } else {
            cout << "(DESTROYED)";
        }
        cout << endl;
    }
}

// Game loop function: (ELSA ZARA BINTI FAKHURRAZI) 
void commenceBattle( vector<Battleships *> &zShip, vector<Battleships *> &rShip, string &winningTeam)
{
    int roundCount = 1; 
    bool zAlive = true;
    bool rAlive = true;

    while (zAlive && rAlive && roundCount <= 200)
    {
        cout << ">>> " << "ROUND" << roundCount << " <<<" << endl;
        // PHASE 1: attack surviving ships
        // ZAPEZOIDS LOOP
        // (WAN WEI SIANG) & (MUHAMMAD YUSUF BIN RIDUAN)
        for (Battleships *z : zShip)
        {
            bool hit = false;
            if (z->canOperate)
            {
                // Only fire Cannons if the ship has enough gunners
                if (z->returnCannonWeapon().ableToShoot) 
                {
                    // For ships containing gunners
                    if(z->currentGunners >= z->requiredGunners && z->requiredGunners > 0){
                        for (gunner *g : z->getGunners())
                        {
                            fightSequence(g, z, hit, rShip, "Cannon");
                        }
                    }

                    // For ships without gunners
                    if (z->requiredGunners == 0 && !z->getPilots().empty())
                    {
                        pilot* p = z->getPilots().front();
                        fightSequence(p, z, hit, rShip, "Cannon");
                    }
                    hit = false; // Reset hit flag
                }

                // Only fire Torpedoes if the ship has enough handlers
                if (z->returnTorpedoWeapon().ableToShoot)
                {
                    if (z->currentTorpedoHandlers >= z->requiredTorpedoHandlers)
                    {
                        for (torpedohandler *t : z->getTorpedoHandlers())
                        {
                            fightSequence(t, z, hit, rShip, "Torpedo");
                        }
                    }
                }
            }
        }
        // ROGOATUSKAN LOOP
        // (WAN WEI SIANG) & (MUHAMMAD YUSUF BIN RIDUAN)
        for (Battleships *r : rShip)
        {
            bool hit = false;
            if (r->canOperate)
            {
                if (r->returnCannonWeapon().ableToShoot)
                {
                    if (r->currentGunners >= r->requiredGunners && r->requiredGunners > 0)
                    {
                        for (gunner *g : r->getGunners())
                        {
                            fightSequence(g, r, hit, zShip, "Cannon");
                        }
                    }

                    if (r->requiredGunners == 0 && !r->getPilots().empty())
                    {
                        pilot* p = r->getPilots().front();
                        fightSequence(p, r, hit, zShip, "Cannon");
                    }
                    hit = false;
                }

                if (r->returnTorpedoWeapon().ableToShoot)
                {
                    if (r->currentTorpedoHandlers >= r->requiredTorpedoHandlers)
                    {
                        for (torpedohandler *t : r->getTorpedoHandlers())
                        {
                            fightSequence(t, r, hit, zShip, "Torpedo");
                        }
                    }
                }
            }
        }
        // PHASE 2: update health points and assign ships to be destroyed (MUHAMMAD YUSUF BIN RIDUAN)
        zAlive = false;
        for (Battleships *z : zShip)
        {
            if (z->canOperate)
            {
                z->damageShip();
                z->checkOperationStatus();
            }
            if (z->canOperate)
                zAlive = true;
        }
        
        rAlive = false;
        for (Battleships *r : rShip)
        {
            if (r->canOperate)
            {
                r->damageShip();
                r->checkOperationStatus();
            }
            if (r->canOperate)
                rAlive = true;
        }

        cout << endl;
        cout << "--- Round Status Report ---" << endl;
        fleetReport(zShip, "ZAPEZOID", "Z-S-");
        fleetReport(rShip, "ROGOATUSKAN", "R-S-");
        
        // Counter to the rounds
        roundCount++;
        cout << endl;
    }
    // (MUHAMMAD YUSUF BIN RIDUAN)
    if (!zAlive && !rAlive) {
        winningTeam = "DRAW (BOTH FLEETS DESTROYED)";
    } else if (!zAlive) {
        winningTeam = "ROGOATUSKANS";
    } else if (!rAlive) {
        winningTeam = "ZAPEZOIDS";
    } else {
        winningTeam = "DRAW (AFTER TIMEOUT)";
    }
}
#endif