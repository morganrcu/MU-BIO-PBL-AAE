#define _CRT_SECURE_NO_WARNINGS
#include "pointreader.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//Microsoften unitate-proben frameworka barne hartzen du.


    // KONTZEPTUAN SAKONDUZ: 
    // Unitate-proba softwarearen proba-teknika bat da, non kode-unitaterik txikienak banaka egiaztatzen diren, hala nola funtzioak, behar bezala funtzionatzen dutela ziurtatzeko. 
    // Proba horiek sistemaren gainerakotik isolatuta egiten dira, garapen-zikloan akatsak garaiz identifikatzeko eta zuzentzeko.


namespace UnitTest //namespace bat definitzen du. {} barruko eduki guztia namespace horretakoa da.
{
    TEST_CLASS(PointReaderTest)
    {
    public:
	    
	//Baliozko fitxategi baten irakurketak ongi funtzionatzen duen egiaztatzeko proba-metodo bat definitzen du.
	TEST_METHOD(TestReadingWorksWithValidInput){
	    char const* filename = "points.txt"; //Baliozko fitxategi bat definitzen du.
            struct point_t* points;
            
	    int numberOfPoints = readPoints(filename, &points);//readPoints funtzioari deitzen dio.
	    Logger::WriteMessage("In TestReadingWorksWithValidInput"); //Proben erregistroan mezu bat idazten du.
	    Assert::IsTrue(numberOfPoints > 0); //Fitxategia ondo irakurri bada, puntu kopurua 0 baino handiagoa izan beharko litzateke (hori egiaztatzen da).
        }
	    
        //Fitxategi baliogabe baten irakurketa behar bezala ez dabilela egiaztatzen duen proba-metodoa definitzen du.
	TEST_METHOD(TestReadingNotWorksWithInvalidInput){
            point_t* points;
	    
	    int numberOfPoints = readPoints("invalidpoints.txt", &points);//readPoints funtzioari deitzen dio.
	    Logger::WriteMessage("In TestReadingNotWorksWithInvalidInput");// Proben erregistroan mezu bat idazten du.
	    Assert::AreEqual(numberOfPoints, -1);//Fitxategia ez bada ondo irakurri, funtzioak -1 itzuli beharko luke.
	}

	//Existitzen ez den fitxategi baten irakurketa behar bezala ez dabilela egiaztatzen duen proba-metodo bat definitzen du.
        TEST_METHOD(TestReadingNotWorksWithUnexsistentFile){
            point_t* points;
		
	    int numberOfPoints = readPoints("points.txt", &points);//readPoints funtzioari deitzen dio.
	    Logger::WriteMessage("In TestReadingNotWorksWithUnexsistentFile");// Proben erregistroan mezu bat idazten du.
	    Assert::AreEqual(numberOfPoints, -2);//Fitxategia ez bada existitzen, funtzioak -2 itzuli beharko luke.
        }

        // GEHIAGO:

	//Baliozko fitxategi baten puntuak ondo gordetzen dituen egiaztatzeko proba-metodo bat definitzen du.
        TEST_METHOD(TestReadPointsSuccess){
	    const char* testFile = "test_points.csv"; //Fitxategi bat definitzen du (proba egiteko).
            FILE* fp = fopen(testFile, "w"); //Fitxategia "idazteko moduan" irekitzen du, eta datuak idazten dira bertan.
            fprintf(fp, "t,angle\n");
            fprintf(fp, "0.0,0.0\n");
            fprintf(fp, "1.0,1.0\n");
            fprintf(fp, "2.0,2.0\n");
	    fclose(fp);//Fitxategia ixten du.

            point_t* points = nullptr;//punteroa nullptr-ra hasieratzea praktika ona da. 
	    int result = readPoints(testFile, &points);//readPoints funtzioari deitzen dio.

            Logger::WriteMessage("In TestReadPointsSuccess");// Proben erregistroan mezu bat idazten du.
	    Assert::AreEqual(result, 3);//Funtzioak 3 itzuli beharko luke, puntu kopurua 3 izanik (hori egiaztatzen da).
            Assert::AreEqual(points[0].t, 0.0f);
            Assert::AreEqual(points[0].angle, 0.0f);
            Assert::AreEqual(points[1].t, 1.0f);
            Assert::AreEqual(points[1].angle, 1.0f);
            Assert::AreEqual(points[2].t, 2.0f);
            Assert::AreEqual(points[2].angle, 2.0f);
	    //punktuak ondo irakurri diren egiaztatzen da.

	    free(points);//Puntuak gordetzeko erabilitako memoria askatzen da.
	    remove(testFile);//Sortutako fitxategia ezabatzen da.
        }

	//Zutabe kopuru desegokia duen fitxategia jasotzean errorea ematen duen egiaztatzeko proba-metodo bat definitzen du. 
        TEST_METHOD(TestReadPointsDifferentNumberOfColumns){
	    const char* testFile = "test_points_invalid_columns.csv";//Fitxategi bat definitzen du (proba egiteko).
            FILE* fp = fopen(testFile, "w");//Fitxategia "idazteko moduan" irekitzen du, eta datuak idazten dira bertan.
            fprintf(fp, "t,angle\n");
            fprintf(fp, "0.0,0.0\n");
            fprintf(fp, "1.0\n"); //Balore bakarra duen lerroa idazten da (errorea duena)
            fprintf(fp, "2.0,2.0\n");
	    fclose(fp);//Fitxategia ixten du.

            point_t* points = nullptr;
	    int result = readPoints(testFile, &points);//readPoints funtzioari deitzen dio.
            
	    Logger::WriteMessage("In TestReadPointsDifferentNumberOfColumns");// Proben erregistroan mezu bat idazten du.
	    Assert::AreEqual(result, -1); //Errore bat egon beharko litzateke, eta funtzioak -1 itzuli beharko luke.

            if (points != nullptr) {
		free(points);//Puntuak gordetzeko erabilitako memoria askatzen da.
            }
	    remove(testFile);//Sortutako fitxategia ezabatzen da.
        }

    };
   
}
