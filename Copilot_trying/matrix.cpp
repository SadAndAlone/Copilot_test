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
// --- Metody ---
matrix& matrix::alokuj(int newSize) {
    if (!data || newSize != n) {
        if (data) {
            for (int i = 0; i < n; ++i)
                delete[] data[i];
            delete[] data;
        }
        n = newSize;
        allocateMemory(n);
    }
    return *this;
}

matrix& matrix::wstaw(int x, int y, int wartosc) {
    if (x >= 0 && x < n && y >= 0 && y < n) {
        data[x][y] = wartosc;
    }
    return *this;
}

int matrix::pokaz(int x, int y) const {
    if (x >= 0 && x < n && y >= 0 && y < n) {
        return data[x][y];
    }
    return 0;
}

matrix& matrix::dowroc() {
    matrix temp(*this);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            data[i][j] = temp.data[j][i];
    return *this;
}

matrix& matrix::losuj() {
    std::srand(std::time(nullptr));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            data[i][j] = std::rand() % 10;
    return *this;
}

matrix& matrix::losuj(int x) {
    std::srand(std::time(nullptr));
    for (int i = 0; i < x; ++i) {
        int r = std::rand() % n;
        int c = std::rand() % n;
        data[r][c] = std::rand() % 10;
    }
    return *this;
}