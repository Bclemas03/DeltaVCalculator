//Helix Industries SolDeltaVCalculator
//by Benjamin Clemas
//V2

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;


//code inspired by A Taylor's Hohmann Transfer Orbit Analysis https://github.com/ATaylorAerospace/HohmannHET
//nonetheless restructured and rewriten as required but still utalising the same core forumula as is the Hohmann Transfer Formula in C++

class Hohmann{
    private:
        //MU for gravitation standard in km^3
        double MU;
        //RU for radius of planet in km
        double RU;
        //R1 for radius of orbit 1 in km
        double R1;
        //R2 for radius of orbit 2 in km
        double R2;

    public:
    
        Hohmann(double mu, double ru, double r1, double r2){
            MU = mu;
            RU = ru;
            R1 = r1;
            R2 = r2;
        }
        

        void transfer(){
            //Adds R1 to RU to factor in the diameter of the planet with the diameter of the orbit
            R1 = R1 + RU;
            R2 = R2 + RU;

            //calculates radius input and specific angular momentum assuming circular orbits
            double a_transfer = ((R1 + R2) * 0.5);
            double h1 = sqrt(MU * (2.0/R1 - 1.0/a_transfer));
            double h2 = sqrt(MU * (2.0/R2 - 1.0/a_transfer));

            //calculates acceleration to reach r1 and r2 with graviational parameter for main body 
            double v1 = sqrt(MU / R1);
            double v2 = sqrt(MU / R2);

            //calculates total deltav requried by removing specific angular momentum from deltav calculations
            double v = (h1 - v1) + (v2 - h2);

            //calls printer for displaying
            print(h1, h2, a_transfer, v1, v2, v);
        }

        //calculates time taken to complete transer between r1 and ru orbits within gravitational parameter of main body
        double time(double a_transfer){
            //returns output in minutes format, default is seconds
            return sqrt(pow(a_transfer, 3) / MU) / 60;
        }

        //outputs calculated veriables
        void print(double h1, double h2, double a_transfer, double v1, double v2, double v){
            cout <<"\nCalculating...\n\n"
            "CALCULATION COMPLETE:\n"
            "============================================\n"
            "Initial Orbit Altitude: " << R1-RU << " km\n"
            "--------------------------------------------\n"
            "Final Orbit Altitude: " << R2-RU << " km\n"
            "--------------------------------------------\n"
            "Transfer Orbit Semi-Major Axis: " << R2-RU << " km\n"
            //"--------------------------------------------\n"
            ////Broken for interplanety transfers
            //"Departure Burn DeltaV Required: ~" << v1 << " km/s\n"
            //"--------------------------------------------\n"
            //"Arrival Burn DeltaV Required: ~" << v2 << " km/s\n"
            "--------------------------------------------\n"
            "Total DeltaV Required: ~" << v << " km/s\n"
            "--------------------------------------------\n"
            "Transfer Time: " << time(a_transfer) << " minutes\n"
            "============================================\n\n";
        }
};

//// code for independent testing if .h turned to .cpp
// int main()
// {
//     string origin;
//     cout << "Enter Origin: ";
//     cin >> origin;

//     string destination;
//     cout << "Enter Destination: ";
//     cin >> destination;

//     if (origin == destination){
//         double r1 = 0.0;
//         cout << "enter r1: ";
//         cin >> r1;

//         double r2 = 0.0;
//         cout << "enter r2: ";
//         cin >> r2;

//         Hohmann hohmann(MU[origin], RU[origin], r1, r2);
//         hohmann.transfer();
//     }
    
//     else{
//         Hohmann hohmann(MU["sun"], RU["sun"], AU[origin], AU[destination]);
//         hohmann.transfer();
//     }

//     return 0;
// }