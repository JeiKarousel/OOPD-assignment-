#include <iostream>
#include <vector>
#include "BattleshipClasses.h"
#include "functions.h"
#include <random>

using namespace std;

// setting the seed
random_device rnd;
mt19937 gen(rnd());

template <typename Ship>

// function to set bool
void SetBool(vector<Battleships *> &ShipVector)
{
    for (Battleships *s : ShipVector)
    {
        if (s->currentPilots == 0)
            s->SetOperationFalse();
    }
}

// function to set percentages
void SetPercentages(vector<Battleships *> &ShipVector)
{
    for (Battleships *s : ShipVector)
    {
        // if the pilots are less than the required pilots, increase both hitbyCannon and hitbyTorpedo by 25%
        if ((s->currentPilots < s->requiredPilots) && s->currentPilots > 0)
        {
            short newhitCannon;
            short newhitTorpedo;

            newhitCannon = (s->gethitByCannon() * 25 / 100) + s->gethitByCannon();
            if (newhitCannon > 100)
                newhitCannon = 100;

            newhitTorpedo = (s->gethitByTorpedo() * 25 / 100) + s->gethitByTorpedo();
            if (newhitTorpedo > 100)
                newhitTorpedo = 100;

            s->SethitByCannon(newhitCannon);
            s->SethitByTorpedo(newhitTorpedo);
        }
    }
}

void displayHit_Miss(bool hit, Battleships *Ship, crewHolder *Crew, string weapon, Battleships *enemyShip, int damage)
{
    cout << Ship->getShipType() << Ship->getShipName() << "'s" << weapon << Crew->getName() << " fires at " << enemyShip->getShipType() << " " << enemyShip->getShipName() << "...";
    if (hit)
    {
        cout << "HIT! " << "(" << damage << "dmg)" << endl;
    }
    else
    {
        cout << "MISS." << endl;
    }
}

bool Roll_Hit_Miss(Battleships *Ship)
{
    uniform_int_distribution<> dist(0, 99);
    int value = dist(gen);

    // if falls in range then return true
    if (value < Ship->gethitByCannon())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void fight();

int roll(int min, int max)
{
    uniform_int_distribution<> dist(min, max);
    int randomNum = dist(gen);
    return randomNum;
}

Battleships *chooseEnemyShip(vector<Battleships *> enemyShip)
{
    vector<Battleships *> temporary;
    Battleships *chosenShip;
    // roll a random ship
    for (Battleships *e : enemyShip)
    {
        if (e->canOperate)
        {
            temporary.push_back(e);
        }
        // get index of random enemy ship
        int index = roll(0, (temporary.size() - 1));
        chosenShip = temporary[index];
    }
    return chosenShip;
}

void fightSequence(crewHolder *crew, Battleships *s, bool &hit, vector<Battleships *> &enemyShip, string weapon)
{
    // choose the enemy ship
    Battleships *EnemyShip = chooseEnemyShip(enemyShip);
    Battleships *v = chooseEnemyShip(enemyShip);

    // roll to see if the weapon successfully hit or missed the enemy ship
    hit = Roll_Hit_Miss(s);

    if (hit)
    {
        displayHit_Miss(hit, s, crew, weapon, v, s->returnCannonWeapon().power);
        v->UpdateSubtractedHealth(s->returnCannonWeapon().power);
    }
    else
    {
        displayHit_Miss(hit, s, crew, weapon, v, s->returnCannonWeapon().power);
    }
}

void CommenceBattle( vector<Battleships *> &zShip, vector<Battleships *> &rShip)
{
    string winningTeam;
    int totalRounds;

    while (zShip.empty() || rShip.empty())
    {
        // PHASE 1
        // ZAPEZOIDS LOOP
        for (Battleships *z : zShip)
        {
            bool hit = false;
            if (z->canOperate)
            {
                for (gunner *g : z->getGunners())
                {
                    fightSequence(g, z, hit, rShip, "Cannon");
                }
                hit = false;

                for (torpedohandler *t : z->getTorpedoHandlers())
                {
                    fightSequence(t, z, hit, rShip, "Torpedo");
                }
            }
        }

        // ROGOATUSKAN LOOP
        for (Battleships *r : rShip)
        {
            bool hit = false;
            if (r->canOperate)
            {
                for (gunner *g : r->getGunners())
                {
                    fightSequence(g, r, hit, rShip, "Cannon");
                }

                hit = false;

                for (torpedohandler *t : r->getTorpedoHandlers())
                {
                    fightSequence(t, r, hit, rShip, "Torpedo");
                }
            }
        }

        // PHASE 2 -- UPDATE HEALTH POINTS AND ASSIGN SHIPS TO BE DESTROYED
        for (Battleships *z : zShip)
        {
            if (z->canOperate)
            {
                z->UpdateHealth();

                if (z->getHealthPoints() <= 0)
                {
                    z->SetOperationFalse();
                }
            }
        }
        
        for (Battleships *r : rShip)
        {
            if (r->canOperate)
            {
                r->UpdateHealth();

                if (r->getHealthPoints() <= 0)
                {
                    r->SetOperationFalse();
                }
            }
        }
    }
    if(zShip.empty()){
        winningTeam = "ROGOATUSKAN";
    }
    else{
        winningTeam = 
    }
}
