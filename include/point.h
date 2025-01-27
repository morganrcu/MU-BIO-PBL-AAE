#pragma once
#include <stdlib.h>
typedef struct point_t {
	double t;     // Tiempo en segundos
	double theta; // Ángulo en radianes
	double x;
	double y;
	double v;
	double vx;
	double vy;
} point_t;

void freePoints(point_t** points);
