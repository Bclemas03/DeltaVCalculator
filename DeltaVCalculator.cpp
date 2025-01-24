//Helix Industries DeltaV Calculator
//by Benjamin Clemas
//V0.1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map <string, double> dv;
bool run = true;



int main() 
{
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
  dv["Venus Capture"] = dv["Venus Transfer"] + 0.359;
  dv["Venus LVO"] = dv["Venus Capture"] + 2.939;
  

  
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