#include "angularvelocitycalculator.h"
#include <math.h> // fabs erabili ahal izateko

float computeMaximumAngularVelocity(const point_t* points, int numberOfPoints) {
    if (numberOfPoints < 2) {
        return 0.0f; // Ezin da abiadura angeluar maximoa kalkulatu.
    }

    float maxAngularVelocity = 0.0f;//Aldagai honek kalkulatutako abiadura angeluar maximoa gordeko du.

    //Lehenengo puntutik azken-aurreko punturaino array-a zeharkatu 
    for (int i = 0; i < numberOfPoints - 1; i++) {
        float deltaAngle = fabs(points[i + 1].angle - points[i].angle);//Ondoz ondoko bi puntuen arteko angelu-diferentzia kalkulatzen da (rad); balore absolutua erabili da CSV fitxategiak zenbait angelu negatibo eduki ditzakeelako.
        float deltaTime = points[i + 1].t - points[i].t;//Ondoz ondoko bi puntuen arteko denbora-diferentzia kalkulatzen da (s).

        if (deltaTime != 0) { //Denbora-diferentzia 0 bada (ez litzateke gertatu behar), ez da abiadura angeluarra kalkulatzen.
            float angularVelocity = deltaAngle / deltaTime; //Abiadura angeluarraren formula aplikatuz, abiadura angeluarra kalkulatzen da.
            if (angularVelocity > maxAngularVelocity) {
                maxAngularVelocity = angularVelocity; //Abiadura angeluar maximoa eguneratzen da.
            }
        }
    }

    return maxAngularVelocity;
}

// KONTZEPTU GARRANTZITSUA: 
// Abiadura angeluarra kalkulatzeko, ondoz ondoko bi punturen arteko angelu-diferentzia 
// denbora-diferentziaz zatitzen da. 
// Nazioarteko Unitate Sisteman oinarrituz, abiadura angeluarra radianetan segunduko (rad/s) adieraziko da. 
