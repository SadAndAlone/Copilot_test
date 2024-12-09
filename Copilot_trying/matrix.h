#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

class matrix {
private:
    int n;          // Rozmiar macierzy (n x n)
    int** data;     // Wskaźnik na dynamicznie alokowaną macierz

    void allocateMemory(int size);
public:
    // Konstruktory i destruktor
    matrix();
    matrix(int n);
    matrix(int n, int* t);
    matrix(const matrix& m);
    ~matrix();

    // Metody
    matrix& alokuj(int n);
    matrix& wstaw(int x, int y, int wartosc);
    int pokaz(int x, int y) const;
    matrix& dowroc();
    matrix& losuj();
    matrix& losuj(int x);
    matrix& diagonalna(int* t);
    matrix& diagonalna_k(int k, int* t);
    matrix& kolumna(int x, int* t);
    matrix& wiersz(int y, int* t);
    matrix& przekatna();
    matrix& pod_przekatna();
    matrix& nad_przekatna();
    matrix& szachownica();

    // Operatory
    matrix& operator+(const matrix& m);
    matrix& operator*(const matrix& m);
    matrix& operator+(int a);
    matrix& operator*(int a);
    matrix& operator-(int a);
    friend matrix operator+(int a, const matrix& m);
    friend matrix operator*(int a, const matrix& m);
    friend matrix operator-(int a, const matrix& m);
    matrix& operator++(int);
    matrix& operator--(int);
    matrix& operator+=(int a);
    matrix& operator-=(int a);
    matrix& operator*=(int a);
    matrix& operator()(double val);
    friend std::ostream& operator<<(std::ostream& o, const matrix& m);
    bool operator==(const matrix& m) const;
    bool operator>(const matrix& m) const;
    bool operator<(const matrix& m) const;
};

#endif