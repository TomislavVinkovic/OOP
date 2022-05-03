#include "Complex.hpp"

float getRefferenceAngle(float fi) {
    if(fi<0) {
        while(fi < 0) {
            fi += 2*M_PI;
        }
    }
    if(fi > 2*M_PI) {
        while(fi > 2*M_PI) {
            fi -= 2*M_PI;
        }
    }
    return fi;
}

Complex::Complex() : r{0}, fi{0} {}
Complex::Complex(float m, float im) {
    r = m;
    fi = getRefferenceAngle(im);
}
Complex::Complex(const Complex& c){
    r = c.r;
    fi = c.fi;
    fi = getRefferenceAngle(fi);
}

float Complex::getModul() const {
    return r;
}

float Complex::getArgument() const {
    return fi;
}

void Complex::setModul(float m) {
    r = m;
}

void Complex::setArgument(float arg) {
    fi = getRefferenceAngle(arg);
    std::cout << "fi: " << fi << std::endl;
}

Complex& Complex::operator=(const Complex& c) {
    this->setArgument(c.fi);
    this->setModul(c.r);
    return *this;
}

Complex& Complex::operator*=(const Complex& c) {
    r *= c.r;
    fi += c.fi;
    fi = getRefferenceAngle(fi);
    return *this;
}

Complex& Complex::operator/=(const Complex& c) {
    r /= c.r;
    fi -= c.fi;
    fi = getRefferenceAngle(fi);
    return *this;
}

Complex Complex::operator*(const Complex& c) const{
    Complex c1{*this};
    c1 *= c;
    return c1;
}

Complex Complex::operator/(const Complex& c) const {
    Complex c1{*this};
    c1 /= c;
    return c1;
}

bool Complex::operator==(const Complex& c) const {
    return fi == c.fi && r == c.r;
}

bool Complex::operator!=(const Complex& c) const {
    return !(*this == c);
}

Complex Complex::potencija(int a) {
    
    float tempR = pow(r, a);
    float tempFi = getRefferenceAngle(a*fi);
    Complex c1{tempR, tempFi};
    
    return c1;
}

void Complex::print() {
    std::cout << r << " * " << 
        "(cos " << fi << " + i*sin " << fi << ")"
        << std::endl;
}