#include "angularvelocitycalculator.h"
#include <stdio.h>
#include <math.h>
    
    //cada punto tiene una estructura definida como point_t, que contiene las coordenadas x, y, t
    //la funci�n recibe un array de puntos y el n�mero de puntos

    float computeMaximumAngularVelocity(const point_t * points, int numberOfPoints) {
        
        float maxAngularVelocity = 0.0f;
        //inicializar la variable maxAngularVelocity a 0.0 (con un sufijo f para indicar que es un valor de tipo float en lugar de double)

        for (int i = 1; i < numberOfPoints; i++) {
            // Calcular la diferencia de coordenadas y tiempo entre dos puntos continuos
            float deltaX = points[i].x - points[i - 1].x;
            float deltaY = points[i].y - points[i - 1].y;
            float deltaT = points[i].t - points[i - 1].t;

            // Evitar divisi�n por cero en deltaT
            if (deltaT <= 0.0f) {
                continue; //no se ejecutar�n las instrucciones que vienen despu�s de esta l�nea del bucle.
            }

            // Calcular el cambio de �ngulo (Delta Theta)
            float deltaTheta = atan2(deltaY, deltaX);

            // Calcular la velocidad angular
            float angularVelocity = deltaTheta/ deltaT;

            // Actualizar la velocidad angular m�xima
            if (fabs(angularVelocity) > fabs(maxAngularVelocity)) {
                maxAngularVelocity = angularVelocity;
            }
        }
        
        return maxAngularVelocity;
    }

