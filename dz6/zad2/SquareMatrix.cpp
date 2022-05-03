#include "SquareMatrix.hpp"
#include <iostream>

void SquareMatrix::empty() {
    if(container != nullptr) {
        for(int i = 0; i<M; i++) {
            delete container[i];
        }
        delete container;
    }
}

void SquareMatrix::copy(const SquareMatrix& matrix) {
    M = matrix.M;
    container = new double*[M];
    for(int i = 0; i<M; i++) {
        container[i] = new double[M];
        for(int j = 0; j<M; j++) {
            container[i][j] = matrix.container[i][j];
        }
    }
}

SquareMatrix::SquareMatrix(unsigned int M) {
    this->M = M;
    container = new double*[M];

    for(int i = 0; i<M; i++) {
        container[i] = new double[M];
        for(int j = 0; j<M; j++) {
            container[i][j] = 0;
        }
    }
}

SquareMatrix::SquareMatrix(const SquareMatrix& matrix) {
    empty();
    copy(matrix);
}

SquareMatrix::~SquareMatrix() {
    empty();
}

void SquareMatrix::print() const {
    for(int i = 0; i<M; i++) {
        for(int j = 0; j<M; j++) {
            std::cout << container[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

double* SquareMatrix::operator[](unsigned int m) {
    //opet, neka se user brine o out of bounds :)
    return container[m];
}

const double* SquareMatrix::operator[](unsigned int m) const {
    return container[m];
}

SquareMatrix& SquareMatrix::operator=(const SquareMatrix& matrix) {
    empty();
    copy(matrix);

    return *this;
}

//moguce je zbrajati samo matrice istih dimenzija
SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& matrix) {

    if(M != matrix.M) {
        std::cout << "Upozorenje: matrice razlicitih dimenzija. Vracam prvu matricu kao defaultnu vrijednost." << std::endl;
        return *this;
    }

    for(int i = 0; i<M; i++) {
        for(int j = 0; j<M; j++) {
            container[i][j] += matrix.container[i][j];
        }
    }
    return *this;
}

//moguce je zbrajati samo matrice istih dimenzija
SquareMatrix& SquareMatrix::operator-=(const SquareMatrix& matrix) {

    if(M != matrix.M) {
        std::cout << "Upozorenje: matrice razlicitih dimenzija. Vracam prvu matricu kao defaultnu vrijednost." << std::endl;
        return *this;
    }

    for(int i = 0; i<M; i++) {
        for(int j = 0; j<M; j++) {
            container[i][j] -= matrix.container[i][j];
        }
    }
    return *this;
}

//posebno testirati mnozenje
SquareMatrix& SquareMatrix::operator*=(const SquareMatrix& matrix) {
    double newVal{};
    if(M != matrix.M) {
        std::cout << "Upozorenje: matrice razlicitih dimenzija. Vracam prvu matricu kao defaultnu vrijednost." << std::endl;
        return *this;
    }

    
    double** newContainer = new double*[M];

    for(int i = 0; i<M; i++) {
        newContainer[i] = new double[M];
        for(int j = 0; j<M; j++) {
            newVal = 0;
            for(int k = 0; k<M; k++) {
                newVal += container[i][k] * matrix.container[k][j];
            }
            newContainer[i][j] = newVal;
        }
    }
    empty();
    container = newContainer;


    return *this;
}

SquareMatrix SquareMatrix::operator+(const SquareMatrix& matrix) {

    SquareMatrix m(*this);
    m += matrix;
    return m;

}

SquareMatrix SquareMatrix::operator-(const SquareMatrix& matrix) {

    SquareMatrix m(*this);
    m -= matrix;
    return m;

}

SquareMatrix SquareMatrix::operator*(const SquareMatrix& matrix) {

    SquareMatrix m(*this);
    m *= matrix;
    return m;

}

SquareMatrix& SquareMatrix::operator=(double val) {
    for(int i = 0; i<M; i++) {
        for(int j = 0; j<M; j++) {
            container[i][j] = val;
        }
    }
    return *this;
}

SquareMatrix& SquareMatrix::operator+=(double val) {
    for(int i = 0; i<M; i++) {
        for(int j = 0; j<M; j++) {
            container[i][j] += val;
        }
    }
    return *this;
}

SquareMatrix& SquareMatrix::operator-=(double val) {
    for(int i = 0; i<M; i++) {
        for(int j = 0; j<M; j++) {
            container[i][j] -= val;
        }
    }
    return *this;
}

SquareMatrix& SquareMatrix::operator*=(double val) {
    for(int i = 0; i<M; i++) {
        for(int j = 0; j<M; j++) {
            container[i][j] *= val;
        }
    }
    return *this;
}

SquareMatrix& SquareMatrix::operator/=(double val) {
    for(int i = 0; i<M; i++) {
        for(int j = 0; j<M; j++) {
            container[i][j] /= val;
        }
    }
    return *this;
}

SquareMatrix SquareMatrix::operator+(double val) const {
    SquareMatrix M(*this);
    M += val;

    return M;
}

SquareMatrix SquareMatrix::operator-(double val) const {
    SquareMatrix M(*this);
    M -= val;

    return M;
}

SquareMatrix SquareMatrix::operator*(double val) const {
    SquareMatrix M(*this);
    M *= val;

    return M;
}

SquareMatrix SquareMatrix::operator/(double val) const {
    SquareMatrix M(*this);
    M /= val;

    return M;
}