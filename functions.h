#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


bool check_File_isCSV(const string filename)
{
    if (!(filename.substr(filename.size() - 4) == ".csv"))
    {
        cout << "Invalid type of file! " << endl;
        return 1;
    }
}

bool check_Sides(const string filename)
{
    if (filename.size() <= 4)
    {
        cout << "Invalid filename!" << endl;
    }

    if (filename[0] == 'z')
    {
        return isZapezoid = true;
    }
    else if (filename[0] == 'r')
    {
        return isRogoatuskan = true;
    }
    else
    {
        cout << "Invalid name of file! Please specify type of ship/crew! " << endl;
        return 1;
    }

    if (filename.substr(1, (filename.size() - 4)) == "Ships" || filename.substr(1, (filename.size() - 5)) == "Ships")
    {
        isShips = true;
    }
    else if (filename.substr(1, (filename.size() - 4)) == "Crew" || filename.substr(1, (filename.size() - 5)) == "Crew")
    {
        isCrew = true;
    }
    else
    {
        cout << "Invalid filename!" << endl;
        return 1;
    }
}