#include "point.h"
#include "pointreader.h"
#include "angularvelocitycalculator.h"
#include <stdio.h> // Incluir la cabecera correcta para printf

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("Program to compute maximum angular velocity from a txt file of comma separated values produced by Tracker\n");
		printf("Usage: %s <filename>\n", argv[0]);
		return -1;
	}

	struct point_t* points = nullptr; // Inicializar el puntero a nullptr

	int numberOfPoints = readPoints(argv[1], &points);

	if (numberOfPoints < 0)
	{
		printf("Error reading file\n");
		return -1;
	}
	float maximumAngularVelocity = computeMaximumAngularVelocity(points, numberOfPoints);

	maximumAngularVelocity = static_cast<float>(maximumAngularVelocity * 8 * (60 / (2 * 3.14))); // Usar static_cast para la conversión

	printf("Maximum angular velocity: %f rpm\n", maximumAngularVelocity);

	freePoints(&points);
	return 0;
}
