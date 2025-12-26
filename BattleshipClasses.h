#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

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
class Guerriero : public shipHolder{

    public:
    Guerriero(string SHIP_ID, string SHIP_name) : shipHolder( SHIP_ID, SHIP_name) {}
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

