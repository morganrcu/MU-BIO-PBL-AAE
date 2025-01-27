#include <csv.h>
#include <stdio.h>
#include "point.h"
#include "pointreader.h"
#include "angularvelocitycalculator.h"
//Programarako beharrezkoak diren goiburuak. (point.h, pointreader.h, angularvelocitycalculator.h) 
//programako funtzio eta egituren adierazpenak dituzten proiektuko fitxategi espezifikoen goiburuak dira

int main(int argc, char** argv) {
	//argc (argument count) komando-lerrotik programara pasatzen den argumentu-kopurua da, programaren izena barne. 
	//argv (argument vector) argumentuak duen kate-array bat da.

	if (argc != 2) {
		printf("Program to compute maximum angular velocity from a txt file of comma separated values produced by Tracker\n");
		printf("Usage: %s <filename>\n", argv[0]);
		return -1;
	}
	//Erabiltzaileak fitxategiaren izena sartu duela egiaztatzen du.
	//Hala ez bada, erabilera-mezu bat inprimatzen du eta -1 (errorea) itzultzen du. 

	struct point_t* points;

	int numberOfPoints = readPoints(argv[1], &points); //readPoints funtzioa deitzen du, csv fitxategian irakurritako puntu-kopurua itzultzen duena.

	if (numberOfPoints < 0) {
		printf("Error reading file\n");
		return -1;
	}
	//fitxategia irakurtzean errorerik izan den egiaztatzen du (numberOfPoints 0 baino txikiagoa bada). 
	// Hala bada, errore-mezua inprimatzen du eta -1 (errorea) itzultzen du. 

	float maximumAngularVelocity = computeMaximumAngularVelocity(points, numberOfPoints);
	//computeMaximumAngularVelocity funtziora deitzen du, abiadura angeluar maximoa itzultzen duena. 


	printf("Maximum angular velocity: %f rad/s\n", maximumAngularVelocity); //Abiadura angeluar maximoa inprimatzen du.

	freePoints(&points);
	//freePoints funtziora deitzen du, puntuen array-rako esleitutako memoria askatzen duena. 

	return 0;
}
