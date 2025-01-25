#include <stdlib.h>
#include "point.h"
void freePoints(point_t** points) {
    if (points && *points) { // Verificar que el puntero es v�lido
        free(*points);
        *points = NULL; // Evitar punteros colgantes
    }
}