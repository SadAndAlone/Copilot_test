#include "matrix.h"

// --- Pomocnicza funkcja alokująca pamięć ---
void matrix::allocateMemory(int size) {
    data = new int* [size];
    for (int i = 0; i < size; ++i) {
        data[i] = new int[size]();
    }
}