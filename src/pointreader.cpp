#define _CRT_SECURE_NO_WARNINGS
#include "pointreader.h"
#include "point.h"
#include <stdio.h>
#include <stdlib.h>

int readPoints(const char* file, point_t** points) {
    FILE* fp = fopen(file, "r");
    if (!fp) {
        printf("Error opening file: %s\n", file);
        return -1;
    }

    size_t capacity = 1000; // Capacidad inicial
    *points = (point_t*)malloc(capacity * sizeof(point_t));
    if (!*points) {
        fclose(fp);
        printf("Memory allocation failed\n");
        return -1;
    }

    int count = 0;
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%lf,%lf,%lf,%lf,%lf,%lf,%lf",
            &(*points)[count].t, &(*points)[count].x, &(*points)[count].y,
            &(*points)[count].vx, &(*points)[count].vy, &(*points)[count].v,
            &(*points)[count].theta) == 7) {
            count++;
            if (count >= capacity) {
                capacity *= 2;
                *points = (point_t*)realloc(*points, capacity * sizeof(point_t));
                if (!*points) {
                    fclose(fp);
                    printf("Memory reallocation failed\n");
                    return -1;
                }
            }
        }

    }

    fclose(fp);
    return count;
}

