#define _CRT_SECURE_NO_WARNINGS
#include "pointreader.h"
#include <stdio.h>
#include <stdlib.h>

int readPoints(const char* PBLtracker, point_t** points)
{
    FILE* fp = fopen(PBLtracker, "r");
    if (!fp) return -2; // Archivo no encontrado

    int capacity = 10;
    *points = (point_t*)malloc(capacity * sizeof(point_t));
    if (!*points) return -1; // Error al asignar memoria

    int count = 0;
    while (!feof(fp))
    {
        if (count >= capacity)
        {
            capacity *= 2;
            point_t* temp = (point_t*)realloc(*points, capacity * sizeof(point_t));
            if (!temp)
            {
                free(*points);
                return -1; // Error de reasignación
            }
            *points = temp;
        }
        // Suponiendo que el archivo tiene columnas: x, y, t (tres valores por línea)
        if (fscanf_s(fp, "%f,%f,%f\n", &(*points)[count].x, &(*points)[count].y, &(*points)[count].t) == 3)
        {
            count++;
        }
        else
        {
            break; // Error de formato
        }
    }
    fclose(fp);
    return count;
}