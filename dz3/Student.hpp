#pragma once
#include<string>

struct Student {
    int scores[5];
    Student();
    void fillScores(int (&arr)[5]);
    int calculateTotalScore() const;
    void print() const;
};