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
