// SIS210 - Pregunta 3.2 - Cola circular con arreglo
// Compilar: g++ -std=c++17 -Wall -o p3_2 p3_2_cola_circular.cpp && ./p3_2
#include <iostream>
#include <stdexcept>

template<typename T, int CAP>
class ColaCircular {
    T datos[CAP] = {};   // AUXILIAR: "= {}" solo para que las celdas vacias muestren 0 en la traza
    int frente = 0, final_ = 0, tam = 0;
public:
    bool estaVacia() const { return tam == 0; }

    // TODO A: retorna true si la cola esta llena
    bool estaLlena() const {
        // >>> RESPUESTA TODO A >>>
        return tam == CAP;
        // <<< FIN TODO A <<<
    }

    void enqueue(T val) {
        if (estaLlena()) throw std::overflow_error("llena");
        datos[final_] = val;
        final_ = (final_ + 1) % CAP;
        ++tam;
    }

    // TODO B: extraer y retornar el elemento del frente
    T dequeue() {
        // >>> RESPUESTA TODO B >>>
        if (estaVacia()) throw std::underflow_error("vacia");
        T val = datos[frente];               // guardar el elemento del frente
        frente = (frente + 1) % CAP;         // avanzar circularmente
        --tam;
        return val;
        // <<< FIN TODO B <<<
    }

    int size() const { return tam; }

    // >>> AUXILIAR (para imprimir la traza) >>>
    void estado(const char* op, const char* ret) const {
        std::cout << op << " | frente=" << frente << " final_=" << final_
                  << " tam=" << tam << " datos=[";
        for (int i = 0; i < CAP; ++i) std::cout << datos[i] << (i + 1 < CAP ? "," : "");
        std::cout << "] retorna=" << ret << "\n";
    }
    // <<< FIN AUXILIAR <<<
};

int main() {
    ColaCircular<int, 4> q;   // los 0 de datos[] son celdas vacias (sin usar)
    q.estado("inicial    ", "-");
    q.enqueue(1); q.estado("enqueue(1) ", "-");
    q.enqueue(2); q.estado("enqueue(2) ", "-");
    q.enqueue(3); q.estado("enqueue(3) ", "-");
    int a = q.dequeue(); q.estado("dequeue()  ", std::to_string(a).c_str());
    q.enqueue(4); q.estado("enqueue(4) ", "-");
    int b = q.dequeue(); q.estado("dequeue()  ", std::to_string(b).c_str());
    return 0;
}
