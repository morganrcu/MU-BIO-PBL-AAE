#pragma once
#include "point.h"
#include "angularvelocitycalculator.h"
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct point_t {
    float x; // Coordenada x del punto
    float y; // Coordenada y del punto
    float t; // Tiempo asociado al punto
} point_t;

float computeMaximumAngularVelocity(const point_t* points, int numberOfPoints) {
    if (points == NULL || numberOfPoints < 2) {
        // Si no hay suficientes puntos o los datos son nulos, devolvemos 0
        return 0;
    }

    float maxAngularVelocity = 0.0f; // Variable para almacenar la velocidad angular máxima

    for (int i = 1; i < numberOfPoints; ++i) {
        // Calculamos las diferencias de posición (x, y) entre el punto actual y el anterior
        float deltaX = points[i].x - points[i - 1].x;
        float deltaY = points[i].y - points[i - 1].y;

        // Calculamos el ángulo (en radianes) entre los puntos usando atan2
        float angleCurrent = atan2(points[i].y, points[i].x);
        float anglePrevious = atan2(points[i - 1].y, points[i - 1].x);

        // Calculamos la diferencia angular
        float deltaAngle = angleCurrent - anglePrevious;

        // Aseguramos que el ángulo esté en el rango [-pi, pi] para evitar saltos grandes
        while (deltaAngle > M_PI) deltaAngle -= 2 * M_PI;
        while (deltaAngle < -M_PI) deltaAngle += 2 * M_PI;

        // Calculamos el tiempo transcurrido entre los puntos
        float deltaTime = points[i].t - points[i - 1].t;

        if (deltaTime > 0) {
            // Calculamos la velocidad angular
            float angularVelocity = fabs(deltaAngle / deltaTime);

            // Actualizamos la velocidad angular máxima si es mayor que la actual
            if (angularVelocity > maxAngularVelocity) {
                maxAngularVelocity = angularVelocity;
            }
        }
    }

    return maxAngularVelocity;
}

