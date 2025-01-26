#pragma once
typedef struct point_t {
	//TODO 1. Decide what needs to be saved in point_t struct
	//int none; //remove this line, jus to avoid compilation error

	float t;
	float x;
	float y;

} point_t;

void freePoints(point_t** points, int numberOfPoints);