#include<vector>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include <stdexcept>
#include <exception>
#include "PositionVector.hpp"
#include "Student.hpp"
#include "MyVector.hpp"

using namespace std;

vector<string> split(string s, string delimiter) {
    vector<string> retVal;
    size_t start = 0;
    size_t end;
    size_t delimiter_len = delimiter.length();
    string token;

    //dok end pozicija nije van stringa
    while((end = s.find(delimiter, start)) != string::npos) {
        token = s.substr(start, (end-start)); //uzmi substring izmedu delimitera i start pozicije
        start = end + delimiter_len; //uvecaj start poziciju za end + delimiter, odnosno postavi start poslije trenutnog delimitera
        retVal.push_back(token); //pushaj nadeni string u vektor
    }
    retVal.push_back(s.substr(start)); //push backaj zadnji element

    return retVal;

}

vector<Student> getStudentsWithScores(string fileName) {
    int n;
    ifstream scores(fileName);
    if(scores.is_open()) {
        string n_str;
        
        if(getline(scores, n_str)){
            n = stoi(n_str);
            int arr[5]; //neki array od 5 elemenata(znamo koliko ce biti segmenata s bodovima)
            string line;
            vector<Student> students; //imati cemo n studenata na kraju
            for(int i = 0; i<n; i++) {
                getline(scores, line);
                auto points = split(line, " ");

                int j = 0;
                for(const auto &p: points) {
                    arr[j] = stoi(p); //uzmi string koji prestavlja broj bodova i pretvori ga u integer
                    j++;
                }

                Student s;
                s.fillScores(arr);
                students.push_back(s);
            }

            return students;
        }
        else {
            throw runtime_error("Could not read the file properly");
        }

        scores.close();
    }
    else {
        throw runtime_error("Could not open the file");
    }
}

//pomocna funkcija za ispis u drugom zadatku
void printVectorArray(vector<PositionVector> v, string message) {
    cout << message;
    for(auto &v: v) {
        v.print();
    }
    cout << endl;
}

int main() {

    //ZADATAK 1
    vector<PositionVector> posVectors{ 
        PositionVector(2.5, 3.6),
        PositionVector(5.5, 3.6),
        PositionVector(4.4, 4.4),
        PositionVector(10.0, 0.1),
        PositionVector(0.0, 0.0),
    };

    printVectorArray(posVectors, "Prije sortiranja");

    sort(posVectors.begin(), posVectors.end(), [](const PositionVector& v1, const PositionVector& v2) {
        return v1.norm() > v2.norm();
    });

    printVectorArray(posVectors, "Nakon sortiranja");
    

    //ZADATAK 2
    try {
        vector<Student> students = getStudentsWithScores("data.txt");
        double pero_points = students.at(0).calculateTotalScore();
        for(auto& s: students) {
            s.print();
        }
        int vise_od_pere = count_if(students.begin()+1, students.end(), [&pero_points](const Student& s1){
            return s1.calculateTotalScore() >= pero_points;
        });
        cout << "Broj studenata koji imaju vise bodova od Pere: " << vise_od_pere << endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    MyVector v;
    for(int i = 1; i<=10; i++) {
        v.pushBack(i);
    }

    cout << "Vektor v: ";
    for(auto &a: v) {
        cout << a << " ";
    }
    cout << endl;

    cin.get();
    return 0;
}