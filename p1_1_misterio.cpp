// SIS210 - Examen Parcial Unidad I - Pregunta 1.1
// Compilar: g++ -std=c++17 -Wall -o p1_1 p1_1_misterio.cpp && ./p1_1
#include <iostream>
#include <vector>

// Codigo original del examen (con un contador agregado para verificar a mano)
int misterio(std::vector<int>& A, int n, long long& comparaciones) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // >>> AGREGADO (comprobacion) >>>
            ++comparaciones;                 // contamos cada vez que se ejecuta el if
            // <<< FIN <<<
            if (A[i] > A[j])
                res++;
        }
    }
    return res;
}

int main() {
    struct Caso { const char* nombre; std::vector<int> A; };
    std::vector<Caso> casos = {
        {"Mejor  (ordenado)", {1, 2, 3, 4, 5, 6}},
        {"Peor   (inverso) ", {6, 5, 4, 3, 2, 1}},
        {"Normal (mezclado)", {38, 15, 27, 5, 42, 11}},
    };
    for (auto& c : casos) {
        long long comp = 0;
        int n = (int)c.A.size();
        int r = misterio(c.A, n, comp);
        std::cout << c.nombre << " -> retorna " << r
                  << " | comparaciones = " << comp
                  << " | n(n-1)/2 = " << n * (n - 1) / 2 << "\n";
    }
    return 0;
}
