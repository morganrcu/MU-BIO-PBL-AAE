#pragma once
typedef struct point_t {
	double t;
    double x;
    double y;
} point_t;

void freePoints(point_t** points);