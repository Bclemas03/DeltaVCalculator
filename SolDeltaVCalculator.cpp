//Helix Industries SolDeltaVCalculator
//by Benjamin Clemas
//V2

#include <iostream>
#include <bits/stdc++.h>
#include "Sol.h"
#include "Hohmann.h"
using namespace std;



string target;
bool run = true;


void DVLoad(){
  cout << "\n|====================================|"
  "\n|Welcome to the Sol DeltaV Calculator!|"
  "\n|------------------------------------+------------------------------------------------|"
  "\n|Calculations are done based on the Wikipedia Commons Library Solar System DeltaV Map.|"
  "\n|Assumptions:                                                                         |"
  "\n| - Craft is in orbit of origin                                                       |"
  "\n| - Origin and Destination are in their orbits average distance of the Sun            |"
  "\n| - Burns are calcuated at Periapsis                                                  |"
  "\n| - Gravity assist and inclination changes are ignored                                |"
  "\n| - Acceleration is instant                                                           |"
  "\n|                                                                                     |"
  "\n| All outputs are in DeltaV I.e. Km/s^2                                               |"
  "\n| !WARNING OUTPUTS ARE APPROXIMATIONS!                                                |"
  "\n| Type !help for commands and help                                                    |"
  "\n|=====================================================================================|" << endl;
}

void DVSearch(Sol sol){
  cout << "Solar System LOADED!\n";

  while (run){
    cout << 
    "\nEnter Desired Origin"
    "\nE.g. (Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, or Neptune)"
    "\nenter blank to stop \n\n> ";
    
    string origin;
    getline(cin, origin);
    transform(origin.begin(),origin.end(),origin.begin(),::tolower);
    
    if (origin == "!help"){
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
      if (origin.empty()){
        run = false;
      }
      if (sol.AU[origin] == 0 && origin != "sun") {
          cout << "ERROR: Target Not Found"
          "\nPlease enter valid Target"
          "\nif help needed type !help\n\n";
      }

      else {
        cout << 
        "\nEnter Desired Destination"
        "\nE.g. (Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, or Neptune)\n\n> ";
        
        string destination;
        getline(cin, destination);
        transform(destination.begin(),destination.end(),destination.begin(),::tolower);

        if (origin == destination){
            double r1 = 0.0;
            cout << "Enter Origin Orbit (km): ";
            cin >> r1;

            double r2 = 0.0;
            cout << "Enter Destination Orbit (km): ";
            cin >> r2;

            Hohmann hohmann(sol.MU[origin], sol.RU[origin], r1, r2);
            hohmann.transfer();
        }
    
        else{
            Hohmann hohmann(sol.MU["sun"], sol.RU["sun"], sol.AU[origin], sol.AU[destination]);
            hohmann.transfer();
        }


        
      }
    }
  }
}

int main() 
{
  cout << "LOADING Solar System..." << endl;
  Sol sol;
  DVLoad();

  DVSearch(sol);
  return 0;
} 