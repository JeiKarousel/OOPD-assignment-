#ifndef BattleshipClasses_h
#define BattleshipClasses_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/////////////////////////////////////// ALL CREWS
class crewHolder{
    protected: 
    string crewType, crewName, crewID;

    public:
    crewHolder(string id, string name){

        crewID = id;
        crewName = name;
    }
    virtual ~crewHolder(){}
};

class pilot : public crewHolder{

    public:
    pilot(string CREW_ID, string CREW_name) : crewHolder(CREW_ID, CREW_name) {}
};

class gunner : public crewHolder{
    public:
    gunner(string CREW_ID, string CREW_name) : crewHolder(CREW_ID, CREW_name) {}
};

class torpedohandler : public crewHolder{
    public:
    torpedohandler(string CREW_ID, string CREW_name) : crewHolder(CREW_ID, CREW_name) {}
};

// Base Initialisation of the Battleship format
class Battleships{
    protected:
        int health_points;
        string shipName,shipID;
        short hitByCannon, hitByTorpedo;
        struct weapon{
            short amount;
            int power;
        }lightCannon, torpedo;

    public:
        short requiredPilots, requiredGunners, requiredTorpedoHandlers;
        short currentPilots = 0, currentGunners = 0, currentTorpedoHandlers = 0;
        Battleships(int hp, string id, string name){
            health_points = hp;
            shipID = id;
            shipName = name;
        }

        void shipCrew(short pilot, short gunner, short torpedoHandler){
            requiredPilots = pilot;
            requiredGunners = gunner;
            requiredTorpedoHandlers = torpedoHandler;
        }

        void assignPilot(){
            currentPilots++;
        }

        void assignGunner(){
            currentGunners++;
        }

        void assignTorpedoHandler(){
            currentTorpedoHandlers++;
        }
        
        int showLightCannonHitChance(){
            return hitByCannon;
        }

        int showTorpedoHitChance(){
            return hitByTorpedo;
        }

        void damageTaken(int damage){
            health_points -= damage;
        }

        int getHealthPoints(){
            return health_points;
        }

        string getShipName(){
            return shipName;
        }
};

/////////////////////////////// ALL ARE Z
class Guerriero : public Battleships{

    public:
    Guerriero(int hp, string id, string name) : Battleships(123, id, name){
        short hitByCannon = 26;
        short hitByTorpedo = 6;
        lightCannon.power = 96;
        lightCannon.amount = 1;
        shipCrew(1,0,0);
    }
};

class Medio : public Battleships{
      
    public:
    Medio(int hp, string id, string name) : Battleships(214, id, name){
        short hitByCannon = 31;
        short hitByTorpedo = 11;
        lightCannon.power = 134;
        lightCannon.amount = 2;
        shipCrew(1,2,0);
    }
};
class Corazzata : public Battleships{
      
    public:
    Corazzata(int hp, string id, string name) : Battleships(1031, id, name){
        short hitByCannon = 50;
        short hitByTorpedo = 25;
        lightCannon.power = 164;
        lightCannon.amount = 10;
        torpedo.power = 293;
        torpedo.amount = 4;
        shipCrew(2,10,4);
    }
};

/////////////////////////////////// ALL ARE R
class Jager : public Battleships{
    public:
    Jager(int hp, string id, string name) : Battleships(112, id, name) {
        short hitByCannon  = 24;
        short hitByTorpedo = 5;
        lightCannon.power  = 101;
        lightCannon.amount = 1;
        shipCrew(1,0,0);
    }
};

class Kreuzer : public Battleships{
    public:
    Kreuzer(int hp, string id, string name) : Battleships(212, id, name) {
        short hitByCannon  = 29;
        short hitByTorpedo = 10;
        lightCannon.power  = 132;
        lightCannon.amount = 2;
        shipCrew(1,2,0);
    }
};

class Fregatte : public Battleships{
    public:
    Fregatte(int hp, string id, string name) : Battleships(1143, id, name) {
        short hitByCannon  = 60;
        short hitByTorpedo = 30;
        lightCannon.power  = 159;
        lightCannon.amount = 11;
        shipCrew(2,11,5);
    }
};

#endif // BattleshipClasses_h