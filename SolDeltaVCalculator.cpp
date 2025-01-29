//Helix Industries SolDeltaVCalculator
//by Benjamin Clemas
//V2.25
#include <iostream>
#include <bits/stdc++.h>
#include "Sol.h"
#include "Hohmann.h"
using namespace std;

//run for search loop
bool run = true;

//info printer for loading and !help
void DVLoad(){
  cout << "\n|====================================|"
  "\n|Welcome to the Sol DeltaV Calculator!|"
  "\n|------------------------------------+------------------------------------------------|"
  "\n|Calculations are done based on the Wikipedia Commons Library Solar System DeltaV Map.|"
  "\n|Assumptions:                                                                         |"
  "\n| - Craft is in orbit of origin                                                       |"
  "\n| - Origin and Destination are in their orbits closest distance to the Sun            |"
  "\n| - Burns are calcuated at Periapsis                                                  |"
  "\n| - Gravity assist and inclination changes are ignored                                |"
  "\n| - Acceleration is instant                                                           |"
  "\n|                                                                                     |"
  "\n| All outputs are in DeltaV I.e. Km/s^2                                               |"
  "\n| !WARNING OUTPUTS ARE APPROXIMATIONS!                                                |"
  "\n| Type !help for commands and help                                                    |"
  "\n|=====================================================================================|" << endl;
}

//search function handling input exceptions and calling hohmann 
void DVSearch(Sol sol){
  cout << "Solar System LOADED!\n";

  //loops searching until blank entered breaking the loop
  while (run){
    cout << 
    "\nEnter Desired Origin:"
    "\nE.g. (Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, or Neptune)"
    "\nenter blank to stop \n> ";
    
    string origin;
    getline(cin, origin);
    transform(origin.begin(),origin.end(),origin.begin(),::tolower);
    
    //detects when help is required and displays all info and special help info
    if (origin == "!help"){
      DVLoad();
      cout <<
      "\n|=====================================================================================|"
      "\n| Valid destinations are in the following format:                                     |"
      "\n| Body Type                                                                           |"
      "\n| Body : being any celestial body in the map e.g. Mercury, Venus, Earth, Mars etc     |"
      "\n| Type : Capture/Escape, Transfer, LO (Low Orbit) if empty type assumes Surface       |"
      "\n| Hope that helps :3 - Benjamin Clemas 2025                                           |"
      "\n|=====================================================================================|\n";
    }

    else {

      //checks if empty has been entered to break the loop or if origin is invalid to restart loop
      if (origin.empty()){
        run = false;
      }

      if (sol.AU[origin] == 0 && origin != "sun") {
          cout << "ERROR: Origin Not Found"
          "\nPlease enter valid Target"
          "\nif help needed type !help\n\n";
      }

      else {
        cout << 
        "\nEnter Desired Destination:"
        "\nE.g. (Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, or Neptune)\n> ";
        
        string destination;
        getline(cin, destination);
        transform(destination.begin(),destination.end(),destination.begin(),::tolower);

        
        //checks if empty has been entered to break the loop or if destination is invalid to restart loop
        if (destination.empty()){
          run = false;
        }
        
        if (sol.AU[destination] == 0 && destination != "sun") {
          cout << "ERROR: Destination Not Found"
          "\nPlease enter valid Target"
          "\nif help needed type !help\n\n";
        }

        //checks if orgin == destination for local hohmann transfer calculation
        else {
          if (origin == destination){
            double r1 = 0.0;
            cout << "\nEnter Origin Orbit (km):\n> ";
            cin >> r1;

            double r2 = 0.0;
            cout << "\nEnter Destination Orbit (km):\n> ";
            cin >> r2;

            Hohmann hohmann(sol.MU[origin], sol.RU[origin], r1, r2);
            hohmann.transfer();
            cin.ignore();
          } 
    
          //otherwise performs international hohmann transfer
          //by pretenting it is a local transfer in orbit of the sun. By setting r1 and r2 to the origin and destinations closets orbits to the sun to minimise deltaV
          else{
              Hohmann hohmann(sol.MU["sun"], sol.RU["sun"], sol.AU[origin], sol.AU[destination]);
              hohmann.transfer();
          }
        }
      }
    }
  }
}

int main() 
{
  //loads the solar object which stores planets their masses, diameters and closest distances from the sun needed for simulating solar system for hohman inputs.
  cout << "LOADING Solar System..." << endl;
  Sol sol;
  
  DVLoad();

  DVSearch(sol);
  return 0;
} 