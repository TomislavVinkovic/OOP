#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include<iostream>

class Complex {
    protected:
        float r, fi;
    public:
        Complex();
        Complex(float, float);
        Complex(const Complex&);
        float getModul() const;
        float getArgument() const;
        void setModul(float);
        void setArgument(float);
        Complex potencija(int);
        Complex& operator=(const Complex&);
        Complex& operator*=(const Complex&);
        Complex& operator/=(const Complex&);
        Complex operator*(const Complex&) const;
        Complex operator/(const Complex&) const;
        bool operator==(const Complex&) const;
        bool operator!=(const Complex&) const;
        void print();
};
float getRefferenceAngle(float);