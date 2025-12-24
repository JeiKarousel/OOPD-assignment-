#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

struct weapon{
    short power = 96;
};

class Battleships{
    private:
        int health_points;
        std::vector<std::string> pilots;
        weapon light_cannon;

    public:
        Battleships(){
            health_points = 100;

        }  
        void damageTaken(int damage){
            health_points -= damage;
        }
        void addPilot(std::string pilotName){
            pilots.push_back(pilotName);
        }
};

