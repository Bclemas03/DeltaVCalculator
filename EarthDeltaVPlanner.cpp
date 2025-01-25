//Helix Industries DeltaVPlanner
//by Benjamin Clemas
//V1
#include <iostream>
#include <bits/stdc++.h>
#include "SolDeltaVMap.h"
using namespace std;



string target;
bool run = true;


void DVLoad(){
  cout << "\n|====================================|"
  "\n|Welcome to the Earth DeltaV Planner!|"
  "\n|------------------------------------+------------------------------------------------|"
  "\n|Calculations are done based on the Wikipedia Commons Library Solar System DeltaV Map.|"
  "\n|Assumptions:                                                                         |"
  "\n| - Craft is on Earth near the Equator                                                |"
  "\n| - Craft is in the perfect launch window for the destination                         |"
  "\n| - Burns are calcuated at Periapsis                                                  |"
  "\n| - Gravity assist and inclination changes are ignored                                |"
  "\n|                                                                                     |"
  "\n| All outputs are in DeltaV I.e. Km/s^2                                               |"
  "\n| !WARNING OUTPUTS ARE APPROXIMATIONS!                                                |"
  "\n| Type !help for commands and help                                                    |"
  "\n|=====================================================================================|" << endl;
}

void DVSearch(map<string, double> dv){
  cout << "DELTAV MAP LOADED!\n";

  while (run){
    cout << 
    "\nEnter Desired Destination"
    "\nE.g. (Moon, Earth LO, Mars Capture/Escape, Sun Transfer, etc)"
    "\nenter blank to stop \n\n> ";
    
    string target;
    getline(cin, target);
    transform(target.begin(),target.end(),target.begin(),::tolower);

    if (target == "!help"){
      DVLoad();
      cout <<
      "\n|=====================================================================================|"
      "\n| Valid destinations are in the following format:                                     |"
      "\n| Body Type                                                                           |"
      "\n| Body : being any celestial body in the map e.g. Mercury, Venus, Earth, Mars etc     |"
      "\n| Type : Capture/Escape, Transfer, LO (Low Orbit) if empty type assumes Surface       |"
      "\n| Hope that helps :3 - Benjamin Clemas 2025                                           |"
      "\n|=====================================================================================|" << endl;
    }

    else {
      if (target.empty()){
      run = false;
      }

      else {
        double dvalue = dv[target];

        if (dvalue == 0 && target != "earth") {
          cout << "ERROR: Target Not Found"
          "\nPlease enter valid Target"
          "\nif help needed type !help\n\n";
        }
        else{
          target[0] = toupper(target[0]);
          cout << "Calculating...\n'" << target << "' can be reached with:\n " << dvalue << " DeltaV (KM/s^2)\n" << endl;
        }
      }
    }
  }
}

int main() 
{
  cout << "LOADING DELTAV MAP..." << endl;
  DeltaVMap dvMap;
  DVLoad();

  DVSearch(dvMap.main());
  return 0;
} 