#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "pointreader.h"

//CSV fitxategi batetik puntuak irakurtzeko funtzioa (struct-en array batean gordetzen ditu puntuak eta puntu-kopurua itzultzen du).

    int readPoints(const char* file, point_t** points) {
	FILE* fp = fopen(file, "r"); //Fitxategia "irakurtzeko moduan" ireki ("r"); fopen-ek punteroa itzultzen fitxategia behar bezala ireki bada. Fitxategia ezin bada ireki NULL itzuliko du.
        if (fp == NULL) {
	    return -2; //Fitxategia ezin bada ireki, -2 itzultzen du.
        }

	int capacity = 1; //struct-en array-ak hasiera batean izango duen gehienezko edukiera (progresiboki handituz joango da). 
        int size = 0;//irakurritako puntu kopurua.
        *points = (point_t*)malloc(capacity * sizeof(point_t)); // Memoria esleitzen du array-rako.
        if (*points == NULL) {
            fclose(fp);
            return -1; //Erroreren bat egongo balitz, fitxategia ixten du.  
        }

	char line[128]; //Fitxategian lerroak irakurtzeko erabiliko den buffer-a. 

        //Lehen bi lerroak baztertzen dira, ez dutelako punturik (aldagaien izena bakarrik)
        fgets(line, sizeof(line), fp); 
        fgets(line, sizeof(line), fp);

	//Fitxategiko lerroak irakurtzen ditu, eta puntuak struct-en array-an gordetzen ditu.
        while (fgets(line, sizeof(line), fp)) {
	    //Memoria berresleitu
            if (size >= capacity) {
                capacity *= 2; //Array-aren uneko tamaina kapazitatera iristen bada, kapazitatea bikoiztu egiten da.
                point_t* temp = (point_t*)realloc(*points, capacity * sizeof(point_t)); //Memoria berresleitzen du struct-en array-rako
                if (temp == NULL) {
                    free(*points);
                    fclose(fp);
		    return -1; //Memoria beresleitzean errore bat egon balitz, fitxategia ixten du, eta memoria askatzen du.
                }
                *points = temp;
            }

            //Irakurritako lerrotik float motako bi balio point_t egituran gordetzen dira, t eta angle-en, array-aren size posizioan.
	    //2 balore ez baleude, errorea emango du, fitxategia itxi eta memoria askatzen du. 
	    if (sscanf(line, "%f,%f", &(*points)[size].t, &(*points)[size].angle) != 2) { 
                free(*points);
                fclose(fp);
                return -1; 
            }
		
	    size++; //Inolako errorerik ez badago, puntu kopurua inkrementatzen da.
        }
            fclose(fp); //Fitxategia ixten du.
	    return size; //Array-an gordetako puntu kopurua itzultzen du.
    }
