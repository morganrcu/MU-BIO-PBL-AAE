#include <math.h>
#include "angularvelocitycalculator.h"

float computeMaximumAngularVelocity(const point_t* points, int numberOfPoints) {
    if (numberOfPoints < 2) return 0.0f; 

    float maxAngularVelocity = 0.0f;
    for (int i = 1; i < numberOfPoints; i++) {
        float dx = points[i].x - points[i - 1].x;
        float dy = points[i].y - points[i - 1].y;
        float dt = points[i].t - points[i - 1].t;

        if (dt <= 0) continue; 

        float angularVelocity = fabs(atan2(dy, dx) / dt);
        if (angularVelocity > maxAngularVelocity) {
            maxAngularVelocity = angularVelocity;
        }
    }
    return maxAngularVelocity;
}
