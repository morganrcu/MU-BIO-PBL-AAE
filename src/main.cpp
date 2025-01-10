#include <csv.h>
#include <stdio.h>
#include "pointreader.h"
#include "point.h"
#include "angularvelocitycalculator.h"

int main(int argc, char ** argv) {
	if (argc != 2) {
		printf("Program to compute maximum angular velocity from a txt file of comma separated values produced by Tracker\n");
		printf("Usage: %s <filename>\n", argv[0]);
		return -1;
	}
	struct point_t* points;

	int numberOfPoints = readPoints(argv[1], &points);

	if (numberOfPoints < 0) {
		printf("Error reading file\n");
		return -1;
	}
	float maximumAngularVelocity = computeMaximumAngularVelocity(points, numberOfPoints);
	
	printf("Maximum angular velocity: %f\n", maximumAngularVelocity);

	freePoints(&points);
	return 0;
}