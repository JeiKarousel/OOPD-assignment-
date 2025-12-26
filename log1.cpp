// // Xylo TT3L
// // Elsa Zara Binti Fakhurrazi
// // Muhammad Yusuf Bin Riduan
// // Wan Wei Siang
// // Syed Zaki Husain Wafa

// // TO REMOVE:
// // In addition to normal things like explaining the purpose of the code, etc. also comment as to who wrote a particular
// // piece of code, method, or even part of a method, if more than one person made changes to a method. If you did
// // pair programming for a particular piece of code, write both names.

// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>
// #include <vector>
// #include "BattleshipClasses.h"
// using namespace std;

// bool isZapezoid = false;
// bool isRogoatuskan = false;
// bool isCrew = false;
// bool isShips = false;

// bool check_File_isCSV(const string filename)
// {

//     if (!(filename.substr(filename.size() - 4) == ".csv"))
//     {

//         cout << "Invalid type of file! " << endl;
//         return 1;
//     }
// }

// bool check_Sides(const string filename)
// {
//     if (filename.size() <= 4)
//     {
//         cout << "Invalid filename!" << endl;
//     }

//     if (filename[0] == 'z')
//     {
//         return isZapezoid = true;
//     }
//     else if (filename[0] == 'r')
//     {
//         return isRogoatuskan = true;
//     }
//     else
//     {
//         cout << "Invalid name of file! Please specify type of ship/crew! " << endl;
//         return 1;
//     }

//     if (filename.substr(1, (filename.size() - 4)) == "Ships" || filename.substr(1, (filename.size() - 5)) == "Ships")
//     {
//         isShips = true;
//     }
//     else if (filename.substr(1, (filename.size() - 4)) == "Crew" || filename.substr(1, (filename.size() - 5)) == "Crew")
//     {
//         isCrew = true;
//     }
//     else
//     {
//         cout << "Invalid filename!" << endl;
//         return 1;
//     }
// }

// int main(int argc, char *argv[])
// {
//     vector<shipHolder*> zShipTest;
//     vector<shipHolder*> sShipTest;
//     vector<crewHolder*> zCrewTest;
//     vector<crewHolder*> sCrewTest;

//     string userInput1, Input2, content;
//     string SHIP_id, SHIP_name, SHIP_type;
//     string shipContent, shipContent, shipContent, shipContent;

//     // format might be different...

//     cout << "Battleship time! Enter the filenames: " << endl;

//     for(int i = 0; i<5; i++){

        

//     }

//     shipContent = argv[1];
    
//     //getline(cin, userInput1);

//     // XyloTT9L zShips1.csv zCrew1.csv rShips1.csv rCrew1.csv
//     //  get the files, separate by spaces
//     // check if every file has .csv, and therefore valid input
//     //  if file cannot open, do
//     stringstream stream1(userInput1);

//     while (getline(stream1, Input2, ' '))
//     {
//         ifstream inFile1;

//         // check if it is a csv file
//         check_File_isCSV(Input2);

//         // check whether it is a Rogoatuskan or a Zapezoids type, and whether it is a crew or ship
//         check_Sides(Input2);

//         inFile1.open(Input2);

//         if (!inFile1.is_open())
//         {
//             cout << "File not found! " << endl;
//             return 1;
//         }
//         // 1SR, Jager, Name1
//         // 2SR, Kreuzer, Name2
//         // 3SR, Fregatte, Name3

//         // possibilities:
//         //  z or s, then in, check if c or s
//         if (isZapezoid)
//         {
//             // all zaps
//             if (isShips)
//             {
//                 //getting one line from the fstream (line from file content)
//                 while (getline(inFile1, content, '\n')){

//                     stringstream stream2(content);
//                     // get id, shiptype then name
//                     getline(stream2, SHIP_id, ',');
//                     getline(stream2, SHIP_type, ',');
//                     getline(stream2, SHIP_name);

//                     shipHolder s;
//                     s.shipID = SHIP_id;
//                     s.shipType = SHIP_type;
//                     s.shipName = SHIP_name;

//                     zShipTest.push_back(s);
//                 }

//                 inFile1.close();

//             }
//         }

//         if (isCrew)
//         {
//         }
//     }

//     return 0;
// }