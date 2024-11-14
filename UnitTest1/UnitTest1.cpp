// UnitTest1.cpp
#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_Lab№10.1A/AP_Lab№10.1A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
    TEST_CLASS(UnitTest1) {
public:
    TEST_METHOD(TestCalculateHighGradesPercentage) {
        const int N = 3;
        Student* s = new Student[N];

        // Тестові дані
        s[0].physicsGrade = 5;
        s[1].physicsGrade = 4;
        s[2].physicsGrade = 3;

        double result = CalculateHighGradesPercentage(s, N);
        Assert::AreEqual(66.67, result, 0.01); // 2 з 3 студентів мають оцінку 4 або 5

        delete[] s;
    }

    TEST_METHOD(TestAverageCalculation) {
        const int N = 1;
        Student* s = new Student[N];

        s[0].physicsGrade = 4;
        s[0].mathGrade = 5;
        s[0].csGrade = 3;

        double avg = (s[0].physicsGrade + s[0].mathGrade + s[0].csGrade) / 3.0;
        Assert::AreEqual(4.0, avg, 0.01);

        delete[] s;
    }
    };
}