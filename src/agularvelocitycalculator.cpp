#include "angularvelocitycalculator.h"
#include <math.h>

float computeMaximumAngularVelocity(const point_t* points, int numberOfPoints) {
    if (numberOfPoints < 2) {
        return 0.0f; // No se puede calcular la velocidad angular con menos de 2 puntos
    }

    float maxAngularVelocity = 0.0f;

    for (int i = 1; i < numberOfPoints; ++i) {
        double deltaX = points[i].x - points[i - 1].x;
        double deltaY = points[i].y - points[i - 1].y;
        double deltaT = points[i].time - points[i - 1].time;

        if (deltaT != 0) {
            float angularVelocity = sqrt(deltaX * deltaX + deltaY * deltaY) / deltaT;
            if (angularVelocity > maxAngularVelocity) {
                maxAngularVelocity = angularVelocity;
            }
        }
    }

    return maxAngularVelocity;
}


