#include <stdio.h>
#include "point.h"
#include "pointreader.h"
#include "angularvelocitycalculator.h"

int main(int argc, char** argv) {
	/*
		ARGUMENTOS:

		int main(int argc, char *argv[]);

			argc (argument count):
				Es un entero que indica el número de argumentos pasados al programa, incluyendo el nombre del programa en sí.
				Siempre es al menos 1 porque el primer argumento (argv[0]) es el nombre del ejecutable.

			argv (argument vector):
				Es un array de punteros a cadenas (char *) que contiene los argumentos pasados al programa.

				- argv[0] es el nombre (o ruta) del programa.
				- argv[1] hasta argv[argc-1] son los argumentos adicionales.
				- argv[argc] es un puntero nulo (NULL), marcando el final del array.
	*/

	if (argc != 2) {
		printf("Program to compute maximum angular velocity from a txt file of comma separated values produced by Tracker\n");
		printf("Usage: %s <filename>\n", argv[0]);

		return -1;
	}

	struct point_t* points = NULL;

	int numberOfPoints = readPoints(argv[1], &points);

	if (numberOfPoints < 2) {
		printf("Error: no hay suficientes puntos");
		return -1;
	}

	float maximumAngularVelocity = computeMaximumAngularVelocity(points, numberOfPoints);

	printf("Maximum angular velocity: %.20f  [rad/s]\n", maximumAngularVelocity);

	/*
	* Lo de abajo es una verificacion de que se han leido bien los puntos. Luego se puede borrar.
	*/

	printf("Num puntos: %d\n\n", numberOfPoints);

	for (int i = 0; i < numberOfPoints; i++) {
		printf("Point %d: t=%.20f, x=%.20f, y=%.20f\n", i, points[i].t, points[i].x, points[i].y);
	}

	freePoints(&points, numberOfPoints );

	return 0;
}