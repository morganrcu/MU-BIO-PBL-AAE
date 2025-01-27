#include <csv.h>
#include <stdio.h>
#include "point.h"
#include "pointreader.h"
#include "angularvelocitycalculator.h"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("Program to compute maximum angular velocity from a txt file of comma separated values produced by Tracker\n");
		printf("Usage: %s <filename>\n", argv[0]);
		return -1;
	}
	struct point_t* points;

	int numberOfPoints = readPoints(argv[1], &points);

	if (numberOfPoints < 0)
	{
		printf("Error reading file\n");
		return -1;
	}
	float maximumAngularVelocity = computeMaximumAngularVelocity(points, numberOfPoints);

	//Como el video esta grabado en camara lenta, 8 veces mas lento de lo normal, multiplicaremos el resultado por 8
	//Aparte, vamos a pasar de radian/segundo a rpm, para ello, lo multiplicaremos por 60/2pi
	maximumAngularVelocity = maximumAngularVelocity * 8 * (60 / (2 * 3.14));

	printf("Maximum angular velocity: %f rpm\n", maximumAngularVelocity);

	freePoints(&points);
	return 0;
}
