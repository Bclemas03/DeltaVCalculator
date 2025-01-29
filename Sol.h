//Helix Industries SolDeltaVMap
//In preperation for V1.5 and V2 which plan to have more complex calculations and source-destination model
//by Benjamin Clemas
//V1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//class storing data for the simulation of solar system in hohmann transfer calculations
//taken from scientific articals and web pages which listed simular calcualations.
class Sol{
  public:

    //mass of plannets in km^3
    map <string, long double> MU =
    {
        {"sun" , 132712440017.987},
        {"mercury" , 22032.0804864179},
        {"venus" , 324858.59882646},
        {"earth" , 398600.432896939},
        {"moon" , 4902.80058214776},
        {"mars" , 42828.3142580671},
        {"jupiter" , 126686537.857796},
        {"europa" , 3200.999806720590},
        {"saturn" , 37940626.0611373},
        {"uranus" , 5794549.00707187},
        {"neptune" , 6836534.06387926},
        {"io" , 5961.00007464437},
        {"ganymede" , 9886.99742842995},
        {"calliso" , 7180.99840324153}
    };

    //radius of planets in km
    map <string, long double> RU = 
    {
        {"sun", 695700},
        {"venus", 58232},
        {"earth" , 6378.137},
        {"mars" , 3387},
        {"jupiter" , 71492},
        {"europa", 1562.7},
        {"saturn" , 60268},
        {"uranus" , 25559},
        {"neptune", 24764}
    };

    //average distance of planets to Sun in km
    map <string, long double> AU = 
    {
        {"sun", 0},
        {"mercury" , 46000000},
        {"venus" , 107000000},
        {"earth" , 147000000},
        {"mars" , 205000000},
        {"jupiter" , 741000000},
        {"saturn" , 1350000000},
        {"uranus" , 2750000000},
        {"neptune" , 4450000000},
        {"pluto" , 4440000000}

    };
};