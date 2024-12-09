#include "matrix.h"

int main() {
    int n = 4;
    int t[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

    matrix m1;
    matrix m2(n, t);

    std::cout << "Macierz m2:\n" << m3;

    m2.wstaw(0, 0, 42);
    std::cout << "Po wstawieniu 42 do (0, 0):\n" << m2;

    m2.dowroc();
    std::cout << "Po transpozycji:\n" << m2;

    return 0;
}
