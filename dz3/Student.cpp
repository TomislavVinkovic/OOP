#include "Student.hpp"
#include<numeric> //accumulate
#include<iostream>

Student::Student() {}

void Student::fillScores(int(&arr)[5]) {
    for(int i = 0; i<5; i++) {
        scores[i] = arr[i];
    }
}

int Student::calculateTotalScore() const{
    return std::accumulate(scores, scores+4, 0);
}

void Student::print() const{
    for(int i = 0; i<5; i++) {
        std::cout << scores[i] << " ";
    }
    std::cout << std::endl;
}