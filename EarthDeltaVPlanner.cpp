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
  dv["Earth LEO"] = 9.256;
  dv["Earth GEO"] = dv["Earth LEO"] + 2.44;
  dv["Moon Transfer"] = dv["Earth GEO"] + 0.679;
  dv["Moon Capture/Escape"] = dv["Moon Transfer"] + 0.145;
  dv["Moon LMO"] = dv["Moon Capture/Escape"] + 0.676;
  dv["Moon"] = dv["Moon LEO"] + 1.721;

  dv["Earth Capture/Escape"] = dv["Moon Transfer"] + 0.093;
  
  //Venus System
  dv["Venus Transfer"] = dv["Earth Capture/Escape"] + 0.28;
  dv["Venus Capture/Escape"] = dv["Venus Transfer"] + 0.359;
  dv["Venus LVO"] = dv["Venus Capture/Escape"] + 2.939;
  dv["Venus"] = dv["Venus LVO"] + 29.705;

  //Mercury System
  dv["Mercury Transfer"] = dv["Venus Transfer"] + 2.085;
  dv["Mercury Capture/Escape"] = dv["Mercury Transfer"] + 6.31;
  dv["Mercury LMO"] = dv["Mercury Capture/Escape"] + 1.220;
  dv["Mercury"] = dv["Mercury LMO"] + 3.062;

  return dv;
}


int main() 
{
  dv = DeltaVMap();

  while (run) {

    cout << dv["Earth Capture/Escape"] << endl;
    cout << 12.375+0.093;

    string choice;
    cout << "Continue? (Y/N)\n";
    cin >> choice;
    if (choice == "N") {
        run = false;
    }
  
  }

  return 0;
} 