#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include "angularvelocitycalculator.h"

 
// KONTZEPTUAN SAKONDUZ: 
// Unitate-proba softwarearen proba-teknika bat da, non kode-unitaterik txikienak banaka egiaztatzen diren, 
// hala nola funtzioak, behar bezala funtzionatzen dutela ziurtatzeko. 
// Proba horiek sistemaren gainerakotik isolatuta egiten dira, garapen-zikloan akatsak garaiz identifikatzeko eta zuzentzeko.


namespace UnitTest //namespace bat definitzen du. {} barruko eduki guztia namespace horretakoa da.
{
    TEST_CLASS(AngularVelocityTest)
    {
    public:

        TEST_METHOD(TestCommonCase)
            //Proba-metodo honek abiadura angeluar maximoa kalkulatzeko ohiko kasu bat egiaztatzen du,
            //itxuraz berezitasunik ez lukeen kasu sinplea dena.
        {
            point_t points[] = { //puntuak (4) gordetzen dituen array bat definitzen du.
                {0.0, 0.0},
                {1.0, 1.0},
                {2.0, 3.0},
                {3.0, 4.0}
            };
            float result = computeMaximumAngularVelocity(points, 4); //computeMaximumAngularVelocity funtzioari deitzen dio, puntu-kopurua 4 delarik. 
            Logger::WriteMessage("In TestCommonCase");//Proben erregistroan mezu bat idazten du.
            Assert::AreEqual(result, 2.0f); //Abiadura angeluar maximoa 2.0f izan behar du (hori betetzen dela egiaztatzen du).
        }

        TEST_METHOD(TestExtremeCaseFirstPoint)
            //Proba-metodo honek "muturreko" kasu bat egiaztatzen du, non lehen puntuak abiadura angeluar handiena finkatzen duen 
            //(lehen eta bigarren puntuek, hain zuzen ere).
        {
            point_t points[] = { //puntuak (3) gordetzen dituen array bat definitzen du.
                 {0.0, 0.0},
                 {1.0, 10.0},
                 {2.0, 15.0}
            };
            float result = computeMaximumAngularVelocity(points, 3); //computeMaximumAngularVelocity funtzioari deitzen dio, puntu-kopurua 3 delarik.
            Logger::WriteMessage("In TestMaxAngularVelocityFirstPoint"); //Proben erregistroan mezu bat idazten du.
            Assert::AreEqual(result, 10.0f); //Abiadura angeluar maximoa 10.0f izan behar du.
        }

        TEST_METHOD(TestExtremeCaseLastPoint)
            //Proba-metodo honek "muturreko" kasu bat egiaztatzen du, non azkenengo puntuak abiadura angeluar handiena finkatzen duen
            //(azkenengo eta azken aurreko puntuek, hain zuzen ere).
        {
            point_t points[] = {
                {0.0, 0.0},
                {1.0, 5.0},
                {2.0, 20.0}
            };
            float result = computeMaximumAngularVelocity(points, 3); //computeMaximumAngularVelocity funtzioari deitzen dio, puntu-kopurua 3 delarik.
            Logger::WriteMessage("In TestMaxAngularVelocityLastPoint"); //Proben erregistroan mezu bat idazten du.
            Assert::AreEqual(result, 15.0f); //Abiadura angeluar maximoa 15.0f izan behar du.
        }

        TEST_METHOD(TestExtremeCaseHighValues)
            //Proba-metodo honek "muturreko" kasu bat egiaztatzen du, non balioak oso altuak diren. 
        {
            point_t points[] = { //puntuak (3) gordetzen dituen array bat definitzen du.
                {89.0, 50000.0},
                {90.0, 1000000.0},
                {91.0, 2000000.0}
            };
            float result = computeMaximumAngularVelocity(points, 3); //computeMaximumAngularVelocity funtzioari deitzen dio, puntu-kopurua 3 delarik.
            Logger::WriteMessage("In TestExtremeCaseHighValues"); //Proben erregistroan mezu bat idazten du.
            Assert::AreEqual(result, 1000000.0f); // Abiadura angeluar maximoa 1000000.0f izan behar du.
        }

        TEST_METHOD(TestExtremeCaseLowValues)
            //Proba-metodo honek "muturreko" kasu bat egiaztatzen du, non balioak oso txikiak diren.
        {
            point_t points[] = {
                {0.0, 0.0},
                {1.0e-9, 1.0e-9},
                {2.0e-9, 1.5e-9},
                {3.0e-9, 1.6e-9}
            };
            float result = computeMaximumAngularVelocity(points, 3); //computeMaximumAngularVelocity funtzioari deitzen dio, puntu-kopurua 3 delarik.
            Logger::WriteMessage("In TestExtremeCaseLowValues"); //Proben erregistroan mezu bat idazten du.
            Assert::AreEqual(result, 1.0e-9f); // Abiadura angeluar maximoa 1.0e-9f izan behar du.
        }

        TEST_METHOD(TestExtremeCaseNegativeValues)
            //Proba-metodo honek "muturreko" kasu bat egiaztatzen du, non balio batzuk negatiboak diren.
        {
            point_t points[] = { //puntuak (3) gordetzen dituen array bat definitzen du.
                {0.0, 0.0},
                {1.0, -10.0},
                {2.0, -5.0}
            };
            float result = computeMaximumAngularVelocity(points, 3);//computeMaximumAngularVelocity funtzioari deitzen dio, puntu-kopurua 3 delarik.
            Logger::WriteMessage("In TestExtremeCaseNegativeValues");//Proben erregistroan mezu bat idazten du.
            Assert::AreEqual(result, 10.0f); // Abiadura angeluar maximoa 10.0f izan behar du.
        }

        TEST_METHOD(TestErrorCaseEmptyArray)
            //Proba-metodo honek errore-kasu bat egiaztatzen du, non array-a hutsik dagoen.
        {
            point_t* points = nullptr; //points punteroa nullptr-ra hasieratzen du.
            float result = computeMaximumAngularVelocity(points, 0); //computeMaximumAngularVelocity funtzioari deitzen dio, puntu-kopurua 0 delarik.
            Logger::WriteMessage("In TestErrorCaseEmptyArray");//Proben erregistroan mezu bat idazten du.
            Assert::AreEqual(result, 0.0f); // Abiadura angeluar maximoa 0.0f izan behar du, funtzioak inolako punturik jaso ez duelako. 
        }

        TEST_METHOD(TestErrorCaseSinglePoint)
            //Proba-metodo honek errore-kasu bat egiaztatzen du, non array-ak puntu bakarra duen.
        {
            point_t points[] = { //puntuak (1) gordetzen dituen array bat definitzen du.
                {0.0, 1.0}
            };
            float result = computeMaximumAngularVelocity(points, 1); //computeMaximumAngularVelocity funtzioari deitzen dio, puntu-kopurua 1 delarik.
            Logger::WriteMessage("In TestErrorCaseSinglePoint"); //Proben erregistroan mezu bat idazten du.
            Assert::AreEqual(result, 0.0f); // Abiadura angeluar maximoa 0.0f izan behar du, funtzioak, puntu bakarra denez, higitzen ez dela suposatzen duelako.
        }

        TEST_METHOD(TestErrorCaseNonNumericData)
        {
            point_t points[] = {
                {0.0, NAN},
                {1.0, 1.0}
            };
            float result = computeMaximumAngularVelocity(points, 2);
            Logger::WriteMessage("In TestErrorCaseNonNumericData");
            Assert::IsTrue(isnan(result)); // Velocidad angular máxima esperada para datos no numéricos
        }
    };

}
