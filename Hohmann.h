//Helix Industries SolDeltaVCalculator
//by Benjamin Clemas
//V2

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

class Hohmann{
    private:
        double MU;
        double RU;
        double R1;
        double R2;

    public:
    
        Hohmann(double mu, double ru, double r1, double r2){
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