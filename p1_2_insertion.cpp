// SIS210 - Pregunta 1.2 - Traza de Insertion Sort
// Compilar: g++ -std=c++17 -Wall -o p1_2 p1_2_insertion.cpp && ./p1_2
#include <iostream>
#include <vector>

void imprimir(const std::vector<int>& A) {
    std::cout << "[";
    for (size_t i = 0; i < A.size(); ++i)
        std::cout << A[i] << (i + 1 < A.size() ? ", " : "");
    std::cout << "]";
}

int main() {
    std::vector<int> A = {38, 15, 27, 5, 42, 11};
    int total = 0;
    std::cout << "Inicial: "; imprimir(A); std::cout << "\n";

    for (size_t k = 1; k < A.size(); ++k) {
        int clave = A[k];
        int j = (int)k - 1;
        int comp = 0;
        // >>> RESPUESTA: nucleo de Insertion Sort con conteo >>>
        while (j >= 0) {
            ++comp;                          // comparamos A[j] > clave
            if (A[j] > clave) {
                A[j + 1] = A[j];             // desplazar a la derecha
                --j;
            } else break;                    // estricto (>) => es ESTABLE
        }
        A[j + 1] = clave;                    // insertar la clave
        // <<< FIN <<<
        total += comp;
        std::cout << "k=" << k << " clave=" << clave << " -> ";
        imprimir(A);
        std::cout << "  comparaciones=" << comp << "\n";
    }
    std::cout << "Total comparaciones: " << total << "\n";
    return 0;
}
