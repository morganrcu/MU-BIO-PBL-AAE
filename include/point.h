#pragma once
typedef struct point_t {
	float t;// denbora (segundutan)
	float angle; // theta angelua
} point_t;


void freePoints(point_t** points);//point_t array-ari esleitutako memoria askatuko duen funtzio bat deklaratu.


// KODIGOAREN FUNTZIOA: point_t egitura definitzea
// 
// AZALPEN GEHIGARRIAK:
// 
// struct bat datu ezberdinak "entitate" bakar batean biltzen ditu, nolabait. 
// Oso erabilgarria da zenbait propietate erlazionatu duen zerbait adierazteko. 
// Adibidez, plano bateko puntu zehatz bat adierazteko, bere posizio angeluarra
// eta puntu horri dagokion denbora biltzen dituen struct-a erabili daiteke 
// (point_t hori egiten du).
// 
// Typedef erabiliz,point_t kodigoan gehitu daiteke  
// struct-a lehenik idaztzi barik; hala kodea sinplifikatuz. 
