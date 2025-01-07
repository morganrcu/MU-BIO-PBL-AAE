#include <csv.h>
#include <stdio.h>

typedef struct point_t{
	//TODO 1. Decide what needs to be saved in point_t struct
	int none; //remove this line, jus to avoid compilation error
} point_t;

int readPoints(const char * file, point_t ** points){
	//TODO 2. Read the file and save the data in a point_t array
	// Use libcsv: 
	//This sample could be useful https://github.com/rgamble/libcsv/blob/master/csv.pdf
	return -1; //If there is an error reading the file
}

void freePoints(point_t** points) {
	//TODO 2. Free the memory allocated for the point_t array
}

float computeMaximumAngularVelocity(const point_t * points, int numberOfPoints) {
	//TODO 3. Compute the maximum angular velocity
	return 0;
}
int main(int argc, char ** argv) {
	if (argc != 2) {
		printf("Program to compute maximum angular velocity from a txt file of comma separated values produced by Tracker\n");
		printf("Usage: %s <filename>\n", argv[0]);
		return -1;
	}
	point_t* points;

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