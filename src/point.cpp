#include "point.h"
#include <stdlib.h>
#include <stdio.h>

// liberar correctamente la memoria asignada a un array (asignado dinamicamente) de punteros a point_t.
    //La funci�n  debe liberar la memoria asignada tanto para cada elemento del arreglo como para el propio arreglo. 
	
void freePoints(point_t** points, int numberOfPoints) {

        if (points != NULL) {
            // Liberamos la memoria del array de structs
            free(*points);
            printf(".");
            // Ponemos el puntero original a NULL para evitar el uso posterior de memoria liberada
            *points = NULL;
        }

}