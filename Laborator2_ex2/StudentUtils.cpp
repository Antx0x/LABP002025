#include "StudentUtils.h"
#include <cstring>  

int CompareByName(const Student& s1, const Student& s2) {
    return strcmp(s1.GetName(), s2.GetName());
}

int CompareByMathGrade(const Student& s1, const Student& s2) {
    if (s1.GetMathGrade() > s2.GetMathGrade()) return 1;
    if (s1.GetMathGrade() < s2.GetMathGrade()) return -1;
    return 0;
}

int CompareByEnglishGrade(const Student& s1, const Student& s2) {
    if (s1.GetEnglishGrade() > s2.GetEnglishGrade()) return 1;
    if (s1.GetEnglishGrade() < s2.GetEnglishGrade()) return -1;
    return 0;
}

int CompareByHistoryGrade(const Student& s1, const Student& s2) {
    if (s1.GetHistoryGrade() > s2.GetHistoryGrade()) return 1;
    if (s1.GetHistoryGrade() < s2.GetHistoryGrade()) return -1;
    return 0;
}

int CompareByAverageGrade(const Student& s1, const Student& s2) {
    if (s1.GetAverageGrade() > s2.GetAverageGrade()) return 1;
    if (s1.GetAverageGrade() < s2.GetAverageGrade()) return -1;
    return 0;
}
