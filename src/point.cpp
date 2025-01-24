#include "point.h"
#include <cstdlib> // Para usar free

void freePoints(point_t** points) {
    if (points != nullptr) {
        free(*points); // Libera la memoria asignada para el array de point_t
        *points = nullptr; // Establece el puntero a nullptr para evitar accesos inválidos
    }
}
