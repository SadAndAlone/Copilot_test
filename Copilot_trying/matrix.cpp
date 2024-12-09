#include "matrix.h"

// --- Pomocnicza funkcja alokująca pamięć ---
void matrix::allocateMemory(int size) {
    data = new int* [size];
    for (int i = 0; i < size; ++i) {
        data[i] = new int[size]();
    }
}
// --- Konstruktory i destruktor ---
matrix::matrix() : n(0), data(nullptr) {}

matrix::matrix(int n) : n(n) {
    allocateMemory(n);
}

matrix::matrix(int n, int* t) : n(n) {
    allocateMemory(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            data[i][j] = t[i * n + j];
}

matrix::matrix(const matrix& m) : n(m.n) {
    allocateMemory(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            data[i][j] = m.data[i][j];
}

matrix::~matrix() {
    if (data) {
        for (int i = 0; i < n; ++i)
            delete[] data[i];
        delete[] data;
    }
}