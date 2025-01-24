#pragma once
#include "point.h"
int readPoints(const char* file, point_t** points);
int read_csv_header();
struct point_t parse_csv_row(char* fila[]);