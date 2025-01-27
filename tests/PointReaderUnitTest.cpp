#include "pointreader.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(PointReaderTest)
    {
    public:
        TEST_METHOD(TestReadingWorksWithValidInput)
        {
            char const* filename = "validpoints.txt";
            struct point_t* points;

            int numberOfPoints = readPoints(filename, &points);
            Logger::WriteMessage("In TestReadingWorksWithValidInput");
            Assert::IsTrue(numberOfPoints > 0); //If the file is read correctly, the number of points should be greater than 0

            // freePoints(&points);
        }

        TEST_METHOD(TestReadingFailsWithInvalidInput)
        {
            point_t* points;
            int numberOfPoints = readPoints("invalidpoints.txt", &points);

            Logger::WriteMessage("In TestReadingFailsWithInvalidInput");
            Assert::AreEqual(-1, numberOfPoints); //If the file is not read correctly, the function should return -1
        }

        TEST_METHOD(TestReadingFailsWithNonexistentFile)
        {
            point_t* points;
            int numberOfPoints = readPoints("nonexistent.txt", &points);
            Logger::WriteMessage("In TestReadingFailsWithNonexistentFile");
            Assert::AreEqual(-2, numberOfPoints); //If the file does not exist, the function should return -2
        }
    };
}
