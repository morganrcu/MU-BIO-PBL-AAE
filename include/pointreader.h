#pragma once
#include "point.h"
#include <stddef.h>
#include <stdlib.h> // Incluir la biblioteca est�ndar para usar free

int readPoints(const char* file, point_t** points);
