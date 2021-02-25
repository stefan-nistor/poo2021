//
// Created by Stefan on 2/25/2021.
//

#ifndef LAB1_STUDENT_H
#define LAB1_STUDENT_H


class Student {
private:
    char* name;
    float math_grade;
    float engish_grade;
    float history_grade;
public:
    char* getName();
    void setName(char* new_name);

    float getMathGrade();
    float getEnglishGrade();
    float getHistoryGrade();

    void setMathGrade(float grade);
    void setEnglishGrade(float grade);
    void setHistoryGrade(float grade);

    float averageGrade();
};


#endif //LAB1_STUDENT_H
