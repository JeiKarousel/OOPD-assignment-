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

    crewHolder(string a, string b){

        a = crewID;
        b = crewName;
    }
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
        short hitByCannon, hitByTorpedo, requiredPilots, requiredGunners, requiredTorpedoHandlers;
        struct weapon{
            short amount;
            int power;
        }lightCannon, torpedo;

    public:
        Battleships(int hp, string id, string name){
            health_points = hp;
            shipID = id;
            shipName = name;
        }

        void shipCrew(short pilot, short gunner, short torpedoHandler){
            short requiredPilots = pilot;
            short requiredGunners = gunner;
            short requiredTorpedoHandlers = torpedoHandler;
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
    Jager(int hp, string id, string name) : Battleships(123, id, name) {}
};

class Kreuzer : public Battleships{
    public:
    Kreuzer(int hp, string id, string name) : Battleships(214, id, name) {}
};
class Fregatte : public Battleships{
    public:
    Fregatte(int hp, string id, string name) : Battleships(1031, id, name) {}
};



