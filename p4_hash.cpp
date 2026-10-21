// SIS210 - Pregunta 5.1 - Tabla hash con sondeo lineal
// Compilar: g++ -std=c++17 -Wall -o p4 p4_hash.cpp && ./p4
#include <iostream>
#include <vector>

int main() {
    const int M = 11;
    std::vector<int> tabla(M, -1);               // -1 = slot libre
    int claves[] = {22, 33, 44, 55, 18, 29};
    int n = 0;

    // >>> RESPUESTA: insercion con sondeo lineal h(k,i) = (k mod 11 + i) mod 11 >>>
    for (int k : claves) {
        int h = k % M;
        std::cout << "k=" << k << " h(k)=" << h << " :";
        for (int i = 0; i < M; ++i) {
            int slot = (h + i) % M;
            std::cout << " probe" << i << "->slot" << slot;
            if (tabla[slot] == -1) {             // libre: insertar
                tabla[slot] = k;
                ++n;
                std::cout << " (libre) => slot final " << slot
                          << (i > 0 ? "  [hubo colision]" : "") << "\n";
                break;
            }
            std::cout << " (ocupado)";
        }
    }
    // <<< FIN <<<

    std::cout << "\nSlot: ";
    for (int i = 0; i < M; ++i) std::cout << i << "\t";
    std::cout << "\nVal : ";
    for (int i = 0; i < M; ++i) {
        if (tabla[i] == -1) std::cout << "-\t"; else std::cout << tabla[i] << "\t";
    }
    std::cout << "\nFactor de carga alpha = " << n << "/" << M << " = "
              << (double)n / M << "\n";
    return 0;
}
