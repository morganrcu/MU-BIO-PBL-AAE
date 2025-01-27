#include "point.h"
void freePoints(point_t** points) {
if (points != NULL) { // Ziurtatu points ez dela NULL, memoriara sartzeko erroreak saihesteko.
	free(*points); // point_t array-ari esleitutako memoria askatzen du.
	*points = NULL;}
}
