#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
    char name[50];   
    float mathGrade;
    float englishGrade;
    float historyGrade;

public:
    void SetName(const char* newName);
    const char* GetName() const;

    void SetMathGrade(float grade);
    float GetMathGrade() const;

    void SetEnglishGrade(float grade);
    float GetEnglishGrade() const;

    void SetHistoryGrade(float grade);
    float GetHistoryGrade() const;

    float GetAverageGrade() const;
};

#endif
