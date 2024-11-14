// AP_Lab№10.1А.cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

enum Speciality { COMPUTER_SCIENCE, INFORMATICS, MATH_ECONOMICS, PHYSICS_INFORMATICS, LABOR_EDUCATION };
string specialityStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та економіка",
                          "Фізика та інформатика", "Трудове навчання" };

struct Student {
    string surname;
    unsigned course;
    Speciality speciality;
    int physicsGrade;
    int mathGrade;
    int csGrade;
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
void PrintStudentAverages(Student* s, const int N);
double CalculateHighGradesPercentage(Student* s, const int N);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: "; cin >> N;

    Student* s = new Student[N];
    Create(s, N);
    Print(s, N);
    PrintStudentAverages(s, N);

    double percent = CalculateHighGradesPercentage(s, N);
    cout << "Процент студентів, які отримали з фізики 4 або 5: " << percent << "%" << endl;

    delete[] s;
    return 0;
}

void Create(Student* s, const int N) {
    int speciality;
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << " прізвище: "; getline(cin, s[i].surname);
        cout << " курс: "; cin >> s[i].course;
        cout << " спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та економіка, "
            << "3 - Фізика та інформатика, 4 - Трудове навчання): ";
        cin >> speciality;
        s[i].speciality = (Speciality)speciality;
        cout << " оцінка з фізики: "; cin >> s[i].physicsGrade;
        cout << " оцінка з математики: "; cin >> s[i].mathGrade;
        cout << " оцінка з інформатики: "; cin >> s[i].csGrade;
        cout << endl;
    }
}

void Print(Student* s, const int N) {
    cout << "========================================================================================"
        << endl;
    cout << "|  № |  Прізвище  | Курс |      Спеціальність      | Фізика | Математика | Інформатика |"
        << endl;
    cout << "---------------------------------------------------------------------------------------"
        << endl;

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout << "| " << setw(11) << left << s[i].surname
            << "| " << setw(5) << right << s[i].course
            << "| " << setw(24) << left << specialityStr[s[i].speciality]
            << "| " << setw(7) << right << s[i].physicsGrade
            << "| " << setw(11) << right << s[i].mathGrade
            << "| " << setw(11) << right << s[i].csGrade << " |" << endl;
    }
    cout << "========================================================================================"
        << endl;
}

void PrintStudentAverages(Student* s, const int N) {
    cout << "\nСередні бали студентів:" << endl;
    cout << "=============================" << endl;
    cout << "|  Прізвище  | Середній бал |" << endl;
    cout << "=============================" << endl;

    for (int i = 0; i < N; i++) {
        double avg = (s[i].physicsGrade + s[i].mathGrade + s[i].csGrade) / 3.0;
        cout << "| " << setw(11) << left << s[i].surname
            << "| " << setw(12) << fixed << setprecision(2) << right << avg << " |" << endl;
    }
    cout << "=============================" << endl;
}

double CalculateHighGradesPercentage(Student* s, const int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (s[i].physicsGrade >= 4) {
            count++;
        }
    }
    return 100.0 * count / N;
}