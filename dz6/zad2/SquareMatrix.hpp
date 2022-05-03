#pragma once

class SquareMatrix {

    private:
        void empty(); //moja metoda da ne moram kod za praznjenje pasteati na vise mjesta
        void copy(const SquareMatrix&); //isto tako za kopiranje
    public:
        double** container{nullptr};
        unsigned int M;

        //ovo znaci: disableaj defaultni konstruktor pri fazi kompajliranja, cak i za samu klasu
        //ovo uglavnom radi sam kompajler
        SquareMatrix() = delete;
        SquareMatrix(unsigned int);
        SquareMatrix(const SquareMatrix&);
        ~SquareMatrix();

        void print() const;

        //pristupi odredenom stupcu matrice
        double* operator[](unsigned int);
        const double* operator[](unsigned int) const;

        SquareMatrix& operator=(const SquareMatrix&);
        SquareMatrix& operator+=(const SquareMatrix&);
        SquareMatrix& operator-=(const SquareMatrix&);
        SquareMatrix& operator*=(const SquareMatrix&);

        // postavi sve celije na isti skalar
        SquareMatrix& operator=(double);
        // svim celijama nadodaj isti skalar
        SquareMatrix& operator+=(double);
        // od svih celija oduzmi isti skalar
        SquareMatrix& operator-=(double);
        // svaku celiju pomnoži sa skalarom
        SquareMatrix& operator*=(double);
        // svaku celiju podijeli s istim skalarom
        SquareMatrix& operator/=(double);

        SquareMatrix operator+(const SquareMatrix&);
        SquareMatrix operator-(const SquareMatrix&);
        SquareMatrix operator*(const SquareMatrix&);
        
        SquareMatrix operator+(double) const;
        SquareMatrix operator-(double) const;
        SquareMatrix operator*(double) const;
        SquareMatrix operator/(double) const;

        bool operator==(const SquareMatrix&) const;
        bool operator!=(const SquareMatrix&) const;
};