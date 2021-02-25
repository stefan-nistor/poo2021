//
// Created by Stefan on 2/25/2021.
//

#include "Student.h"

void Student::setName(char *new_name) {
    this->name = new_name;
}

char* Student::getName() {
    return this->name;
}

float Student::getMathGrade() {
    return this->math_grade;
}

float Student::getEnglishGrade() {
    return this->engish_grade;
}

float Student::getHistoryGrade() {
    return this->history_grade;
}

void Student::setMathGrade(float grade) {
    this->math_grade = grade;
}

void Student::setEnglishGrade(float grade) {
    this->engish_grade = grade;
}

void Student::setHistoryGrade(float grade) {
    this->history_grade = grade;
}

float Student::averageGrade() {
    return (getHistoryGrade() + getEnglishGrade() + getMathGrade()) / 3.0f;
}

