#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include "angularvelocitycalculator.h"

namespace UnitTest {
    TEST_CLASS(AngularVelocityTest) {
public:
    TEST_METHOD(TestAngularVelocity) {
        point_t points[] = {
            {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
            {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5},
            {2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 1.0}
        };

        float maxAngularVelocity = computeMaximumAngularVelocity(points, 3);
        Assert::AreEqual(0.5f, maxAngularVelocity, 0.01f);
    }
    };
}
