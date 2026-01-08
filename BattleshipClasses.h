#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

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

// EMPTY CLASSES JUST AS PLACEHOLDERS
/////////////////////////////// MAIN PARENT CLASS
class shipHolder{

    public: 
    string shipType, shipName, shipID;

    shipHolder(string a, string b){

        a = shipID;
        b = shipName;
    }
};

/////////////////////////////// ALL ARE Z
class Guerriero : public Battleships{

    public:
    Guerriero(int hp, string id, string name) : Battleships(hp, id, name){
        short hitByCannon = 26;
        short hitByTorpedo = 6;
        lightCannon.power = 96;
        lightCannon.amount = 1;
        shipCrew(1,0,0);
    }
};

class Medio : public shipHolder{
      
    public:
    Medio(string SHIP_ID, string SHIP_name) : shipHolder( SHIP_ID, SHIP_name) {}
};
class Corazzata : public shipHolder{
      
    public:
    Corazzata(string SHIP_ID, string SHIP_name) : shipHolder( SHIP_ID, SHIP_name) {}
};


/////////////////////////////////// ALL ARE R
class Jager : public shipHolder{
    public:
    Jager(string SHIP_ID, string SHIP_name) : shipHolder( SHIP_ID, SHIP_name) {}
};

class Kreuzer : public shipHolder{
    public:
    Kreuzer(string SHIP_ID, string SHIP_name) : shipHolder( SHIP_ID, SHIP_name) {}
};
class Fregatte : public shipHolder{
    public:
    Fregatte(string SHIP_ID, string SHIP_name) : shipHolder( SHIP_ID, SHIP_name) {}
};


/////////////////////////////////////// ALL CREWS
class crewHolder{
    public: 
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

