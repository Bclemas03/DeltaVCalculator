//Helix Industries DeltaV Calculator
//by Benjamin Clemas
//V0.1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map <string, double> dv;
bool run = true;

map <string, double> DeltaVMap(){
  //Earth System
  dv["Earth LO"] = 9.256;
  dv["Earth GEO"] = dv["Earth LO"] + 2.44;

  dv["Moon Transfer"] = dv["Earth GEO"] + 0.679;
  dv["Moon Capture/Escape"] = dv["Moon Transfer"] + 0.145;
  dv["Moon LO"] = dv["Moon Capture/Escape"] + 0.676;
  dv["Moon"] = dv["Moon LO"] + 1.721;

  dv["Earth Capture/Escape"] = dv["Moon Transfer"] + 0.093;
  
  //Mars System
  dv["Mars Transfer"] = dv["Earth Capture/Escape"] + 0.388;
  dv["Mars Capture/Escape"] = dv["Mars Transfer"] + 0.673;
  
  dv["Deimos Transfer"] = dv["Mars Capture/Escape"] + 0.336;
  dv["Deimos Capture/Escape"] = dv["Deimos Transfer"] + 0.649;
  dv["Deimos LO"] = dv["Deimos Capture/Escape"] + 0.002;
  dv["Deimos"] = dv["Deimos LO"] + 0.004;

  dv["Phobos Transfer"] = dv["Deimos Transfer"] + 0.395;
  dv["Phobos Escape/Capture"] = dv["Phobos Transfer"] + 0.535;
  dv["Phobos LO"] = dv["Phobos Escape/Capture"] + 0.003;
  dv["Phobos"] = dv["Phobos LO"] + 0.006;

  dv["Mars LO"] = dv["Phobos Transfer"] + 0.698;
  dv["Mars"] = dv["Mars LO"] + 3.578;

  //Venus System
  dv["Venus Transfer"] = dv["Earth Capture/Escape"] + 0.28;
  dv["Venus Capture/Escape"] = dv["Venus Transfer"] + 0.359;
  dv["Venus LO"] = dv["Venus Capture/Escape"] + 2.939;
  dv["Venus"] = dv["Venus LO"] + 29.705;

  //Mercury System
  dv["Mercury Transfer"] = dv["Venus Transfer"] + 2.085;
  dv["Mercury Capture/Escape"] = dv["Mercury Transfer"] + 6.31;
  dv["Mercury LO"] = dv["Mercury Capture/Escape"] + 1.220;
  dv["Mercury"] = dv["Mercury LO"] + 3.062;

  dv["Sun Transfer"] = dv["Mercury Transfer"] + 15.745;
  dv["Sun LO"] = dv["Sun Transfer"] + 178.107;
  dv["Sun"] = dv["Sun LO"] + 440;

  return dv;
}

void DVLoad(){
  cout << "LOADING DELTAV MAP..." << endl;
  dv = DeltaVMap();
  cout << "LOADING DELTAV MAP LOADED!\n" 
  "|====================================|"<< endl;
  cout <<
  "|Welcome to the Earth DeltaV Planner!|\n"
  "|------------------------------------+------------------------------------------------|"
  "\n|Calculations are done based on the Wikipedia Commons Library Solar System DeltaV Map.|"
  "\n|Assumptions:                                                                         |"
  "\n| - Craft is on Earth near the Equator                                                |"
  "\n| - Craft is in the perfect launch window for the destination                         |"
  "\n| - Burns are calcuated at Periapsis                                                  |"
  "\n| - Gravity assist and inclination changes are ignored                                |"
  "\n|                                                                                     |"
  "\n| All outputs are in DeltaV I.e. Km/s^2                                               |"
  "\n| Type !help for commands and help                                                    |"
  "\n|=====================================================================================|" << endl;
}

void DVSearch(){
  cout << "E";
}

int main() 
{
  DVLoad();

  DVSearch();

  while (run) {

    cout << dv["Sun"] << endl;

    string choice;
    cout << "Continue? (Y/N)\n";
    cin >> choice;
    if (choice == "N") {
        run = false;
    }
  
  }

  return 0;
} 