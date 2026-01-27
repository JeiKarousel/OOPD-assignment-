#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <iostream>
#include <vector>
#include <iomanip>
#include "BattleshipClasses.h"
#include "functions.h"
#include <random>

using namespace std;

extern mt19937 gen;

//roll a random number
int roll(int min, int max)
{
    uniform_int_distribution<> dist(min, max);
    int randomNum = dist(gen);
    return randomNum;
}

// function to set bool
void SetBool(vector<Battleships *> &ShipVector)
{
    for (Battleships *s : ShipVector)
    {
        s->checkOperationStatus();
    }
}

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

// Wan Wei Siang, Elsa Zara
bool Roll_Hit_Miss(Battleships *Target, string weapon)
{
    int value = roll(0, 99);

    if (weapon == "Cannon") {
        return (value < Target->getHitByCannon());
    } 
    else if (weapon == "Torpedo") {
        return (value < Target->getHitByTorpedo());
    }
    return false;
}

Battleships *chooseEnemyShip(vector<Battleships *> enemyShip)
{
    vector<Battleships *> validTargets;
    // roll a random ship
    for (Battleships *e : enemyShip)
    {
        if (e->canOperate)
        {
            validTargets.push_back(e);
        }
    }
    // get index of random enemy ship
    int index = roll(0, (validTargets.size() - 1));
    return validTargets[index];
}

void fightSequence(crewHolder *crew, Battleships *s, bool &hit, vector<Battleships *> &enemyShip, string weapon)
{
    // choose the enemy ship
    Battleships *targetShip = chooseEnemyShip(enemyShip);

    if (targetShip == nullptr)
        return;
    
    // roll to see if the weapon successfully hit or missed the enemy ship
    hit = Roll_Hit_Miss(targetShip, weapon);

    if (hit)
    {
        displayHit_Miss(hit, s, crew, weapon, targetShip, (weapon == "Cannon") ? s->returnCannonWeapon().power : s->returnTorpedoWeapon().power);
        targetShip->totalDamageTaken((weapon == "Cannon") ? s->returnCannonWeapon().power : s->returnTorpedoWeapon().power);
    }
    else
    {
        displayHit_Miss(hit, s, crew, weapon, targetShip, (weapon == "Cannon") ? s->returnCannonWeapon().power : s->returnTorpedoWeapon().power);
    }
}

void fleetReport(vector<Battleships *> &ships, string teamName, string idPrefix) {
   
    cout << teamName << ":"<< endl;
    for (size_t i = 0; i < ships.size(); i++) {
        cout << " [" << idPrefix << setw(3) << i << setfill('0') << (i + 1) << "] ";

        cout << ships[i]->getShipType() << " " << ships[i]->getShipName() << " ";

        if (ships[i]->canOperate) {
            cout << "(" << ships[i]->getHealthPoints() << "/" << ships[i]->getMaxHealth() << ")";
        } else {
            cout << "(DESTROYED)";
        }
        cout << endl;
    }
}

void commenceBattle( vector<Battleships *> &zShip, vector<Battleships *> &rShip, string &winningTeam)
{
    int roundCount = 1; 
    bool zAlive = true;
    bool rAlive = true;

    while (zAlive && rAlive && roundCount <= 200)
    {
        cout << ">>> " << "ROUND" << roundCount << " <<<" << endl;
        // PHASE 1
        // ZAPEZOIDS LOOP
        // Wan Wei Siang, Elsa Zara
        for (Battleships *z : zShip)
        {
            bool hit = false;
            if (z->canOperate)
            {
                // Only fire Cannons if the ship has enough gunners!
                if (z->returnCannonWeapon().ableToShoot) 
                {
                    // For ships contains gunner
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

                // Only fire Torpedoes if the ship has enough handlers!
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
        // Wan Wei Siang, Elsa Zara
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
        // PHASE 2 -- UPDATE HEALTH POINTS AND ASSIGN SHIPS TO BE DESTROYED
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
        
        // counter to see how many rounds
        roundCount++;
        cout << endl;
    }
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