#include "Student.h"
#include <cstring>  

void Student::SetName(const char* newName) {
    if (newName && strlen(newName) < 50) {
        strcpy(name, newName);
    }
}

const char* Student::GetName() const {
    return name;
}

void Student::SetMathGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f)
        mathGrade = grade;
}

float Student::GetMathGrade() const {
    return mathGrade;
}

void Student::SetEnglishGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f)
        englishGrade = grade;
}

float Student::GetEnglishGrade() const {
    return englishGrade;
}

void Student::SetHistoryGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f)
        historyGrade = grade;
}

float Student::GetHistoryGrade() const {
    return historyGrade;
}

float Student::GetAverageGrade() const {
    return (mathGrade + englishGrade + historyGrade) / 3.0f;
}
