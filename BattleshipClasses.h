#ifndef BattleshipClasses_h
#define BattleshipClasses_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <random>


using namespace std;

/////////////////////////////////////// ALL CREWS
class crewHolder
{
protected:
    string crewType, crewName, crewID;

public:
    crewHolder(string id, string name)
    {
        crewID = id;
        crewName = name;
    }
    virtual ~crewHolder() {}

    string getID() {
        return crewID;
    }

    string getName() {
        return crewName;
    }
};

class pilot : public crewHolder
{

public:
    pilot(string CREW_ID, string CREW_name) : crewHolder(CREW_ID, CREW_name) {}
};

class gunner : public crewHolder
{
public:
    gunner(string CREW_ID, string CREW_name) : crewHolder(CREW_ID, CREW_name) {}
};

class torpedohandler : public crewHolder
{
public:
    torpedohandler(string CREW_ID, string CREW_name) : crewHolder(CREW_ID, CREW_name) {}
};

// Base Initialisation of the Battleship format
class Battleships
{
protected:
    int health_points, damageTaken;
    string shipName, shipID, shipType;
    short hitByCannon, hitByTorpedo;
    struct weapon
    {
        short amount;
        int power;
        bool ableToShoot;
    } lightCannon, torpedo;
    vector<pilot*> pilotCrew;
    vector<gunner*> gunnerCrew;
    vector<torpedohandler*> torpedoHandlerCrew;

public:
    bool canOperate = true;
    short requiredPilots, requiredGunners, requiredTorpedoHandlers;
    short currentPilots = 0, currentGunners = 0, currentTorpedoHandlers = 0;

    //Default Constructor
    Battleships()
    {
        health_points = 100;
        shipID = "8008";
        shipName = "Argos";
    }

    Battleships(int hp, string id, string name)
    {
        health_points = hp;
        shipID = id;
        shipName = name;
    }

    //Operator Overloading
    Battleships operator+(Battleships b){
        Battleships c;
        c.hitByCannon = this->hitByCannon + b.hitByCannon;
        c.hitByTorpedo = this->hitByTorpedo + b.hitByTorpedo;
        if(c.hitByCannon > 100)
        {
            c.hitByCannon = 100;
        }
        if(c.hitByTorpedo > 100)
        {
            c.hitByTorpedo = 100;
        }
        return c;
    }

    //Battleship Crew
    void requiredCrew(short pilot, short gunner, short torpedoHandler)
    {
        requiredPilots = pilot;
        requiredGunners = gunner;
        requiredTorpedoHandlers = torpedoHandler;
    }

    void assignPilot(pilot* pilotMember)
    {
        pilotCrew.push_back(pilotMember);
        currentPilots++;
    }

    void assignGunner(gunner* gunnerMember)
    {
        gunnerCrew.push_back(gunnerMember);
        currentGunners++;
    }

    void assignTorpedoHandler(torpedohandler* torpedoHandlerMember)
    {
        torpedoHandlerCrew.push_back(torpedoHandlerMember);
        currentTorpedoHandlers++;
    }

    vector<pilot*> getPilots()
    {
        return pilotCrew;
    }

    vector<gunner*> getGunners()
    {
        return gunnerCrew;
    }

    vector<torpedohandler*> getTorpedoHandlers()
    {
        return torpedoHandlerCrew;
    }

    void checkOperationStatus()
    {
        if(currentTorpedoHandlers < requiredTorpedoHandlers)
        {
            torpedo.ableToShoot = false;
        }

        if(currentGunners < requiredGunners)
        {
            lightCannon.ableToShoot = false;
        }

        if(currentPilots < requiredPilots)
        {   
            Battleships standBy, standBy2;
            standBy.setHitByCannon(hitByCannon);
            standBy.setHitByTorpedo(hitByTorpedo);
            standBy2.setHitByCannon(hitByCannon * 0.25);
            standBy2.setHitByTorpedo(hitByTorpedo * 0.25);
            Battleships sittingDuck = standBy + standBy2;
            setHitByCannon(sittingDuck.getHitByCannon());
            setHitByTorpedo(sittingDuck.getHitByTorpedo());
        }
        else if(currentPilots == 0)
        {
            canOperate = false;
        }
        
        if(health_points <= 0)
        {
            canOperate = false;
        }
    }

    //Light Cannon Stats
    weapon returnCannonWeapon(){
        
        return lightCannon;
    }
    short getHitByCannon()
    {
        return hitByCannon;
    }

    void setHitByCannon(short value)
    {
        hitByCannon = value;
    }

    //Torpedo Stats
    weapon returnTorpedoWeapon()
    {    
        return torpedo;
    }

    short getHitByTorpedo()
    {
        return hitByTorpedo;
    }

    void setHitByTorpedo(short value)
    {
        hitByTorpedo = value;
    }

    //Battleship Stats
    string getShipName()
    {
        return shipName;
    }

    virtual string getShipType() const
    {
        return shipType;
    }

    void totalDamageTaken(short value){
        damageTaken += value;
    }

    void damageShip()
    {
        health_points -= damageTaken;
    }

    int getHealthPoints()
    {
        return health_points;
    }

};

/////////////////////////////// ALL ARE Z
class Guerriero : public Battleships
{

public:
    Guerriero(int hp, string id, string name) : Battleships(123, id, name)
    {
        hitByCannon = 26;
        hitByTorpedo = 6;
        lightCannon.power = 96;
        lightCannon.amount = 1;
        requiredCrew(1, 0, 0);
    }

    string getShipType() const override
    {
        return "Guerriero";
    }
};

class Medio : public Battleships
{

public:
    Medio(int hp, string id, string name) : Battleships(214, id, name)
    {
        hitByCannon = 31;
        hitByTorpedo = 11;
        lightCannon.power = 134;
        lightCannon.amount = 2;
        requiredCrew(1, 2, 0);
    }
    
    string getShipType() const override
    {
        return "Medio";
    }
};
class Corazzata : public Battleships
{

public:
    Corazzata(int hp, string id, string name) : Battleships(1031, id, name)
    {
        hitByCannon = 50;
        hitByTorpedo = 25;
        lightCannon.power = 164;
        lightCannon.amount = 10;
        torpedo.power = 293;
        torpedo.amount = 4;
        requiredCrew(2, 10, 4);
    }

    string getShipType() const override
    {
        return "Corazzata";
    }
};

/////////////////////////////////// ALL ARE R
class Jager : public Battleships
{
public:
    Jager(int hp, string id, string name) : Battleships(112, id, name)
    {
        hitByCannon = 24;
        hitByTorpedo = 5;
        lightCannon.power = 101;
        lightCannon.amount = 1;
        requiredCrew(1, 0, 0);
    }
    string getShipType() const override
    {
        return "Jager";
    }
};

class Kreuzer : public Battleships
{
public:
    Kreuzer(int hp, string id, string name) : Battleships(212, id, name)
    {
        hitByCannon = 29;
        hitByTorpedo = 10;
        lightCannon.power = 132;
        lightCannon.amount = 2;
        requiredCrew(1, 2, 0);
    }
    string getShipType() const override
    {
        return "Kreuzer";
    }
};

class Fregatte : public Battleships
{
public:
    Fregatte(int hp, string id, string name) : Battleships(1143, id, name)
    {
        hitByCannon = 60;
        hitByTorpedo = 30;
        lightCannon.power = 159;
        lightCannon.amount = 11;
        requiredCrew(2, 11, 5);
    }
    string getShipType() const override
    {
        return "Fregatte";
    }
};

#endif // BattleshipClasses_h