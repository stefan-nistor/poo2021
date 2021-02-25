#include  <iostream>
#include <cstring>
#include "Masina.h"
#include "NumberList.h"
#include "Student.h"

int cmpName(Student a, Student b)
{
    int i = 0;
    char* a_name = a.getName();
    char* b_name = b.getName();
    while (a_name[i] && b_name[i])
    {
        if(a_name[i] > b_name[i]) return -1;
        if(a_name[i] < b_name[i]) return 1;
        i++;
    }

    return 0;
}

int cmpAverage(Student a, Student b){
    if(a.averageGrade() > b.averageGrade()) return 1;
    if(a.averageGrade() < b.averageGrade()) return -1;
    return 0;
}

int cmpMath(Student a, Student b){
    if(a.getMathGrade() > b.getMathGrade()) return 1;
    if(a.getMathGrade() < b.getMathGrade()) return -1;
    return 0;
}

int cmpEnglish (Student a, Student b){
    if (a.getEnglishGrade() > b.getEnglishGrade())  return 1;
    if (a.getEnglishGrade() < b.getEnglishGrade())  return -1;
    return 0;
}

int cmpHistory (Student a, Student b){
    if(a.getHistoryGrade() > b.getHistoryGrade())   return 1;
    if(a.getHistoryGrade() < b.getHistoryGrade())   return -1;
    return 0;
}

int main()
{
    return 0;
}
