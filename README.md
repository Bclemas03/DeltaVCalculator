# SolDeltaVCalculator
## Description
The SolDeltaVCalculator uses the Hohmann Transfer Equation to calculate the APPROXIMATE Delta-V required for travel within the Solar System. 

This Calculator is very accurate for local transfers between orbits of a single celestial body. However, due to interplantery transfers being treated as local transfers around the sun the accuracy for interplanety calculations is adequate but not accurate. Improvments will be made when time is avaliable.

## Assumptions
- Craft is in orbit of Origin at 0km for interplanetery calculations, otherwise in origin orbit.
- Origin and Destination planets are in their orbits closest distance of the Sun
- Burns are calcuated at Periapsis
- Gravity assist and inclination changes are ignored
- Acceleration is instant
- All orbits are circular

### DO NOT USE FOR REAL MISSIONS
This is a fun side project and based on the bellow possibly inaccurate DeltaV map.
Outputs are approximations only, in the unlikely event of someone using this for a real mission, run your own numbers.
Don't believe everything you read online, and over estimate DeltaV required, too much fuel is better then too little.

#### Special Thanks
to ATaylor for their work on digitising the Hohmann Transfer into C++. A key resource for the creation of my Hohmann.h code.
In their ATaylor_HohmannTransferOrbitAnalysis_2024, avaliable at
https://github.com/ATaylorAerospace/HohmannHET, which I accessed on 2025-01-29

