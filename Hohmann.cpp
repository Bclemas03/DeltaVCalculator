//Helix Industries DeltaVPlanner
//by Benjamin Clemas
//V1
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

//v is the speed of an orbiting body,
//μm = G M is the standard gravitational parameter of the primary body, assuming M + m is not significantly bigger than M (which makes v M ≪ v (for Earth, this is μ~3.986E14 m3 s−2)
//r  is the distance of the orbiting body from the primary focus,
//a  is the semi-major axis of the body's orbit.

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

class Hohmann{
    private:
        double MU;
        double RU;
        double R1;
        double R2;
    public:
        Hohmann(const double mu, const double ru, const double r1, const double r2){
            MU = mu;
            RU = ru;
            R1 = r1;
            R2 = r2;
        }
        
        void transfer(){

            R1 = R1 + RU;
            R2 = R2 + RU;

            double a_transfer = ((R1 + R2) * 0.5);
            
            double h1 = sqrt(MU * (2.0/R1 - 1.0/a_transfer));
            double h2 = sqrt(MU * (2.0/R2 - 1.0/a_transfer));

            double v1 = sqrt(MU / R1);
            double v2 = sqrt(MU / R2);
            double v = (h1 - v1) + (v2 - h2);

            print(h1, h2, a_transfer, v1, v2, v);
        }

        double time(double a_transfer){
            return sqrt(pow(a_transfer, 3) / MU) / 60;
        }

        void print(double h1, double h2, double a_transfer, double v1, double v2, double v){
            cout<< "Initial Orbit Altitude: " << R1-RU << " km\n"
            << "Final Orbit Altitude: " << R2-RU << " km\n"
            << "Transfer Orbit Semi-Major Axis: " << R2-RU << " km\n"
            << "Departure Burn DeltaV Required: ~" << v1 << " km/s\n"
            << "Arrival Burn DeltaV Required: ~" << v2 << " km/s\n"
            << "Total DeltaV Required: ~" << v << " km/s\n"
            << "Transfer Time: " << time(a_transfer) << " minutes\n";
        }
};

int main()
{
    string source;
    cout << "enter source: ";
    cin >> source;

    double r1 = 0.0;
    cout << "enter r1: ";
    cin >> r1;

    // //radius of orbit 2
    double r2 = 0.0;
    cout << "enter r2: ";
    cin >> r2;
    

    Hohmann hohmann(MU[source],RU[source],r1,r2);
   
    hohmann.transfer();
    // cin;
    return 0;
}