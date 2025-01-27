#define _CRT_SECURE_NO_WARNINGS
#include <cstdio> // Para usar printf
#include "point.h"
#include "angularvelocitycalculator.h"
#include <math.h> // Para fabs

float computeMaximumAngularVelocity(const point_t* points, int numberOfPoints) {
    if (numberOfPoints < 2) {
        printf("Not enough points to calculate angular velocity\n");
        return 0.0f;
    }

    float maxAngularVelocity = 0.0f;

    for (int i = 1; i < numberOfPoints; i++) {
        float deltaTheta = points[i].theta - points[i - 1].theta;
        float deltaTime = points[i].t - points[i - 1].t;


        if (deltaTime != 0) {
            float angularVelocity = fabs(deltaTheta / deltaTime);


            if (angularVelocity > maxAngularVelocity) {
                maxAngularVelocity = angularVelocity;
            }
        }
        else {
            printf("Skipped division by zero at index %d\n", i);
        }
    }


    return maxAngularVelocity;
}
