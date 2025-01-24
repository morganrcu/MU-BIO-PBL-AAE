#define  _CRT_SECURE_NO_WARNINGS
#include "pointreader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readPoints(const char* file, point_t** points) {
    const char* filePath = "C:\\Users\\Jon\\source\\repos\\MU-BIO-PBL-AAE\\PBLtracker.csv";
    FILE* infile = fopen(filePath, "r");
    if (infile == NULL) {
        return -1; // Error al abrir el archivo
    }

    size_t capacity = 10;
    size_t size = 0;
    point_t* pointArray = (point_t*)malloc(capacity * sizeof(point_t));
    if (pointArray == NULL) {
        fclose(infile);
        return -1; // Error al asignar memoria
    }

    char line[256];
    while (fgets(line, sizeof(line), infile)) {
        if (size >= capacity) {
            capacity *= 2;
            point_t* temp = (point_t*)realloc(pointArray, capacity * sizeof(point_t));
            if (temp == NULL) {
                free(pointArray);
                fclose(infile);
                return -1; // Error al reasignar memoria
            }
            pointArray = temp;
        }

        char* time_str = strtok(line, ",");
        char* x_str = strtok(NULL, ",");
        char* y_str = strtok(NULL, ",");

        if (time_str == NULL || x_str == NULL || y_str == NULL) {
            free(pointArray);
            fclose(infile);
            return -1; // Error al analizar la línea
        }

        pointArray[size].time = atof(time_str);
        pointArray[size].x = atof(x_str);
        pointArray[size].y = atof(y_str);
        size++;
    }

    fclose(infile);

    *points = pointArray;
    return (int)size; // Devuelve el número de puntos leídos
}


