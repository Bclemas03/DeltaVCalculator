//Helix Industries DeltaV Calculator
//by Benjamin Clemas
//V1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DeltaVMap{
  public:
    map <string, double> dv;
    void innerSystem(){
      //earth system
      dv["earth lo"] = 9.256;
      dv["earth geo"] = dv["earth lo"] + 2.44;

      dv["moon transfer"] = dv["earth geo"] + 0.679;
      dv["moon capture/escape"] = dv["moon transfer"] + 0.145;
      dv["moon lo"] = dv["moon capture/escape"] + 0.676;
      dv["moon"] = dv["moon lo"] + 1.721;

      dv["earth capture/escape"] = dv["moon transfer"] + 0.093;
      
      //mars system
      dv["mars transfer"] = dv["earth capture/escape"] + 0.388;
      dv["mars capture/escape"] = dv["mars transfer"] + 0.673;
      
      dv["deimos transfer"] = dv["mars capture/escape"] + 0.336;
      dv["deimos capture/escape"] = dv["deimos transfer"] + 0.649;
      dv["deimos lo"] = dv["deimos capture/escape"] + 0.002;
      dv["deimos"] = dv["deimos lo"] + 0.004;

      dv["phobos transfer"] = dv["deimos transfer"] + 0.395;
      dv["phobos escape/capture"] = dv["phobos transfer"] + 0.535;
      dv["phobos lo"] = dv["phobos escape/capture"] + 0.003;
      dv["phobos"] = dv["phobos lo"] + 0.006;

      dv["mars lo"] = dv["phobos transfer"] + 0.698;
      dv["mars"] = dv["mars lo"] + 3.578;

      //venus system
      dv["venus transfer"] = dv["earth capture/escape"] + 0.28;
      dv["venus capture/escape"] = dv["venus transfer"] + 0.359;
      dv["venus lo"] = dv["venus capture/escape"] + 2.939;
      dv["venus"] = dv["venus lo"] + 29.705;

      //mercury system
      dv["mercury transfer"] = dv["venus transfer"] + 2.085;
      dv["mercury capture/escape"] = dv["mercury transfer"] + 6.31;
      dv["mercury lo"] = dv["mercury capture/escape"] + 1.220;
      dv["mercury"] = dv["mercury lo"] + 3.062;

      dv["sun transfer"] = dv["mercury transfer"] + 15.745;
      dv["sun lo"] = dv["sun transfer"] + 178.107;
      dv["sun"] = dv["sun lo"] + 440;
    }

    void asteroidBelt(){
      //asteroid belt
      dv["vesta transfer"] = dv["mars transfer"] + 0.923;
      dv["vesta capture/escape"] = dv["vesta transfer"] + 4.096;
      dv["vesta lo"] = dv["vesta capture/escape"] + 0.102;
      dv["vesta"] = dv["vesta lo"] + 0.173;
      
      dv["ceres transfer"] = dv["vesta transfer"] + 0.379;
      dv["ceres capture/escape"] = dv["ceres transfer"] + 4.381;
      dv["ceres lo"] = dv["ceres capture/escape"] + 0.148;
      dv["ceres"] = dv["ceres lo"] + 0.28;

      dv["pallas transfer"] = dv["ceres transfer"] + 0.003;
      dv["pallas capture/escape"] = dv["pallas transfer"] + 4.562;
      dv["pallas lo"] = dv["pallas capture/escape"] + 0.091;
      dv["pallas"] = dv["pallas lo"] + 0.172;

      dv["hygiea transfer"] = dv["pallas transfer"] + 0.297;
      dv["hygiea capture/escape"] = dv["hygiea transfer"] + 4.915;
      dv["hygiea lo"] = dv["hyigeo capture/escape"] + 0.063;
      dv["hygiea"] = dv["hygiea lo"] + 0.139;
    }

    void gasAndIceGiants(){
      ////jupiter system
      dv["jupiter transfer"] = dv["hygiea transfer"] + 1.099;
      dv["jupiter capture/escape"] = dv["jupiter transfer"] + 0.271;
      //callisto
      dv["callisto transfer"] = dv["jupiter capture/escape"] + 1.114;
      dv["callisto capture/escape"] = dv["callisto transfer"] + 4.025;
      dv["callisto lo"] = dv["callisto capture/escape"] + 0.701;
      dv["callisto"] = dv["callisto lo"] + 1.75;
      //ganymede
      dv["ganymede transfer"] = dv["callisto transfer"] + 0.804;
      dv["ganymede capture/escape"] = dv["ganymede transfer"] + 4.790;
      dv["ganymede lo"] = dv["ganymede capture/escape"] + 0.788;
      dv["ganymede"] = dv["ganymede lo"] + 1.947;
      //nepture system
      dv["europa transfer"] = dv["ganymede transfer"] + 1.055;
      dv["europa capture/escape"] = dv["europa transfer"] + 5.920;
      dv["europa lo"] = dv["europa capture/escape"] + 0.575;
      dv["europa"] = dv["europa lo"] + 1.444;
      //nepture system
      dv["io transfer"] = dv["europa transfer"] + 1.558;
      dv["io capture/escape"] = dv["io transfer"] + 5.783;
      dv["io lo"] = dv["io capture/escape"] + 0.730;
      dv["io"] = dv["io lo"] + 1.781;
      //
      dv["jupiter lo"] = dv["Io transfer"] + 12.667;
      dv["jupiter"] = dv["jupiter lo"] + 33.146;
      ////

      ////saturn system
      dv["saturn transfer"] = dv["jupiter transfer"] + 0.987;
      dv["saturn capture/escape"] = dv["saturn transfer"] + 0.421;
      //lapetus
      dv["lapetus transfer"] = dv["saturn capture/escape"] + 0.301;
      dv["lapetus capture/escape"] = dv["lapetus transfer"] + 2.162;
      dv["lapetus lo"] = dv["lapetus capture/escape"] + 0.162;
      dv["lapetus"] = dv["lapetus lo"] + 0.418;
      //titan
      dv["titan transfer"] = dv["lapetus transfer"] + 0.556;
      dv["titan capture/escape"] = dv["titan transfer"] + 2.202;
      dv["titan lo"] = dv["titan capture/escape"] + 0.656;
      dv["titan"] = dv["titan lo"] + 8.341;
      //rhea
      dv["rhea transfer"] = dv["titan transfer"] + 1.039;
      dv["rhea capture/escape"] = dv["rhea transfer"] + 4.163;
      dv["rhea lo"] = dv["rhea capture/escape"] + 0.129;
      dv["rhea"] = dv["rhea lo"] + 0.298;
      //
      dv["saturn lo"] = dv["rhea transfer"] + 8.328;
      dv["saturn"] = dv["saturn lo"] + 20.413;

      ////uranus system
      dv["uranus transfer"] = dv["saturn transfer"] + 0.690;
      dv["uranus capture/escape"] = dv["uranus transfer"] + 0.513;
      //oberon
      dv["oberon transfer"] = dv["uranus capture/escape"] + 0.46;
      dv["oberon capture/escape"] = dv["oberon transfer"] + 1.621;
      dv["oberon lo"] = dv["oberon capture/escape"] + 0.208;
      dv["oberon"] = dv["oberon lo"] + 0.531;
      //titania
      dv["titania transfer"] = dv["oberon transfer"] + 0.149;
      dv["titania capture/escape"] = dv["titania transfer"] + 1.784;
      dv["titania lo"] = dv["titania capture/escape"] + 0.215;
      dv["titania"] = dv["titania lo"] + 0.546;
      //umbriel
      dv["umbriel transfer"] = dv["titania transfer"] + 0.362;
      dv["umbriel capture/escape"] = dv["umbriel transfer"] + 2.210;
      dv["umbriel lo"] = dv["umbriel capture/escape"] + 0.152;
      dv["umbriel"] = dv["umbriel lo"] + 0.387;
      //ariel
      dv["ariel transfer"] = dv["umbriel transfer"] + 0.346;
      dv["ariel capture/escape"] = dv["ariel transfer"] + 2.318;
      dv["ariel lo"] = dv["ariel capture/escape"] + 0.151;
      dv["ariel"] = dv["ariel lo"] + 0.378;
      //
      dv["uranus lo"] = dv["ariel transfer"] + 4.802;
      dv["uranus"] = dv["uranus lo"] + 15.807;

      ////neptune system
      dv["neptune transfer"] = dv["uranus transfer"] + 0.269;
      dv["neptune capture/escape"] = dv["neptune transfer"] + 0.354;
      //nereid
      dv["nereid transfer"] = dv["nereid capture/escape"] + 0.05;
      dv["nereid capture/escape"] = dv["nereid transfer"] + 0.87;
      dv["nereid lo"] = dv["nereid capture/escape"] + 0.04;
      dv["nereid"] = dv["nereid lo"] + 0.09;
      //triton
      dv["triton transfer"] = dv["nereid transfer"] + 0.740;
      dv["triton capture/escape"] = dv["triton transfer"] + 1.707;
      dv["triton lo"] = dv["triton capture/escape"] + 0.411;
      dv["triton"] = dv["triton lo"] + 1.046;
      //proteus system
      dv["proteus transfer"] = dv["triton transfer"] + 1.38;
      dv["proteus capture/escape"] = dv["proteus transfer"] + 2.9;
      dv["proteus lo"] = dv["proteus capture/escape"] + 0.05;
      dv["proteus"] = dv["proteus lo"] + 0.11;
      //
      dv["neptune lo"] = dv["proteus transfer"] + 4.58;
      dv["neptune"] = dv["neptune lo"] + 16.781;
      ////
    }

    void kuiperBelt(){
      ////pluto system
      dv["pluto transfer"] = dv["neptune transfer"] + 0.117;
      dv["pluto capture/escape"] = dv["pluto transfer"] + 2.703;
      //charon
      dv["charon transfer"] = dv["pluto capture/escape"] + 0.036;
      dv["charon capture/escape"] = dv["charon transfer"] + 0.016;
      dv["charon lo"] = dv["charon capture/escape"] + 0.166;
      dv["charon"] = dv["charon lo"] + 0.427;
      //
      dv["pluto lo"] = dv["pluto capture/escape"] + 0.304;
      dv["pluto"] = dv["pluto lo"] + 0.876;

      //haumea system
      dv["haumea transfer"] = dv["pluto transfer"] + 0.033;
      dv["haumea capture/escape"] = dv["haumea transfer"] + 2.836;
      //hi'iaka
      dv["hi'iaka transfer"] = dv["haumea capture/escape"] + 0.006;
      dv["hi'iaka capture/escape"] = dv["hi'iaka transfer"] + 0.016;
      dv["hi'iaka lo"] = dv["hi'iaka capture/escape"] + 0.031;
      dv["hi'iaka"] = dv["hi'iaka lo"] + 0.097;
      //namaka
      dv["namaka transfer"] = dv["hi'iaka transfer"] + 0.006;
      dv["namaka capture/escape"] = dv["namaka transfer"] + 0.046;
      dv["namaka lo"] = dv["namaka capture/escape"] + 0.012;
      dv["namaka"] = dv["namaka lo"] + 0.045;
      //
      dv["haumea lo"] = dv["hnamaka transfer"] + 0.229;
      dv["haumea"] = dv["haumea lo"] + 0.356;

      //makemake system
      dv["makemake transfer"] = dv["haumea transfer"] + 0.017;
      dv["makemake capture/escape"] = dv["makemake transfer"] + 2.857;
      dv["makemake lo"] = dv["makemake capture/escape"] + 0.209;
      dv["makemake"] = dv["makemake lo"] + 0.517;
    }

    void outerSystem(){
      //eris system
      dv["eris transfer"] = dv["makemake transfer"] + 0.109;
      dv["eris capture/escape"] = dv["eris transfer"] + 1.956;
      dv["eris lo"] = dv["eris capture/escape"] + 0.388;
      dv["eris"] = dv["eris lo"] + 0.937;

      //sedma system
      dv["sedna transfer"] = dv["eris transfer"] + 0.2;
      dv["sedna capture/escape"] = dv["sedna transfer"] + 0.820;
      dv["sedna lo"] = dv["sedna capture/escape"] + 0.150;
      dv["sedna"] = dv["sedna lo"] + 0.290;

      //sun escape
      dv["sun escape"] = dv["sedna transfer"] + 0.03;
    }

    map <string, double> main(){
      innerSystem();
      asteroidBelt();
      gasAndIceGiants();
      kuiperBelt();
      outerSystem();
      return dv;
    }
};

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