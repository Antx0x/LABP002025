#include <iostream>
#include "Student.h"
#include "StudentUtils.h"

int main() {
    Student s1, s2;

    s1.SetName("Alice");
    s1.SetMathGrade(9.0f);
    s1.SetEnglishGrade(8.5f);
    s1.SetHistoryGrade(7.5f);

    s2.SetName("Bob");
    s2.SetMathGrade(7.0f);
    s2.SetEnglishGrade(9.5f);
    s2.SetHistoryGrade(8.0f);

    std::cout << "Comparison by Name: " << CompareByName(s1, s2) << std::endl;
    std::cout << "Comparison by Math Grade: " << CompareByMathGrade(s1, s2) << std::endl;
    std::cout << "Comparison by English Grade: " << CompareByEnglishGrade(s1, s2) << std::endl;
    std::cout << "Comparison by History Grade: " << CompareByHistoryGrade(s1, s2) << std::endl;
    std::cout << "Comparison by Average Grade: " << CompareByAverageGrade(s1, s2) << std::endl;

    return 0;
}
