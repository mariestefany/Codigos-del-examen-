// SIS210 - Preguntas 2.1 y 2.2 - Lista simple
// Compilar: g++ -std=c++17 -Wall -o p2 p2_lista.cpp && ./p2
#include <iostream>

template<typename T>
struct Nodo { T dato; Nodo* sig = nullptr; };

template<typename T>
class ListaSimple {
    Nodo<T>* cabeza = nullptr;
    int tam = 0;
public:
    // >>> AUXILIAR (no es parte de la respuesta; sirve para probar) >>>
    ~ListaSimple() {
        while (cabeza) { Nodo<T>* t = cabeza; cabeza = cabeza->sig; delete t; }
    }
    void insertarFrente(T v) {
        Nodo<T>* n = new Nodo<T>{v, cabeza};
        cabeza = n; ++tam;
    }
    void insertarFinal(T v) {
        Nodo<T>* n = new Nodo<T>{v, nullptr};
        if (!cabeza) cabeza = n;
        else {
            Nodo<T>* p = cabeza;
            while (p->sig) p = p->sig;       // recorrer hasta el ultimo: O(n)
            p->sig = n;
        }
        ++tam;
    }
    void imprimir() const {
        for (Nodo<T>* p = cabeza; p; p = p->sig) std::cout << p->dato << " -> ";
        std::cout << "nullptr  (tam=" << tam << ")\n";
    }
    void crearCicloPrueba() {                // solo para probar tieneCiclo()
        if (!cabeza) return;
        Nodo<T>* p = cabeza;
        while (p->sig) p = p->sig;
        p->sig = cabeza;                     // el ultimo apunta a la cabeza
    }
    void romperCicloPrueba() {               // evita fuga/bucle infinito al destruir
        if (!cabeza) return;
        Nodo<T>* p = cabeza->sig;
        while (p && p != cabeza) p = p->sig;
        if (p == cabeza) {                   // hay ciclo: cortar el ultimo
            Nodo<T>* q = cabeza;
            while (q->sig != cabeza) q = q->sig;
            q->sig = nullptr;
        }
    }
    // <<< FIN AUXILIAR <<<

    // TODO 1: eliminar el nodo con valor 'val' (primera ocurrencia).
    void eliminar(T val) {
        // >>> RESPUESTA TODO 1 >>>
        Nodo<T>* actual = cabeza;
        Nodo<T>* anterior = nullptr;

        while (actual != nullptr && actual->dato != val) {   // buscar
            anterior = actual;
            actual = actual->sig;
        }
        if (actual == nullptr) return;       // no existe: no hace nada

        if (anterior == nullptr)             // caso 1: era la cabeza
            cabeza = actual->sig;
        else                                 // caso 2: medio o final
            anterior->sig = actual->sig;

        delete actual;                       // liberar memoria
        --tam;                               // actualizar tam
        // <<< FIN TODO 1 <<<
    }   // Complejidad: O(n) tiempo, O(1) espacio

    // TODO 2: invertir la lista in-place.
    void invertir() {
        // >>> RESPUESTA TODO 2 >>>
        Nodo<T>* anterior = nullptr;
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            Nodo<T>* siguiente = actual->sig;    // 1. guardar el siguiente
            actual->sig = anterior;              // 2. voltear el puntero
            anterior = actual;                   // 3. avanzar 'anterior'
            actual = siguiente;                  // 4. avanzar 'actual'
        }
        cabeza = anterior;                       // el ultimo nodo es la nueva cabeza
        // <<< FIN TODO 2 <<<
    }   // Complejidad: O(n) tiempo, O(1) espacio

    // TODO 3: detectar ciclo (Floyd).
    bool tieneCiclo() const {
        // >>> RESPUESTA TODO 3 >>>
        Nodo<T>* lento = cabeza;
        Nodo<T>* rapido = cabeza;
        while (rapido != nullptr && rapido->sig != nullptr) {
            lento  = lento->sig;                 // tortuga: 1 paso
            rapido = rapido->sig->sig;           // liebre: 2 pasos
            if (lento == rapido) return true;    // se encontraron => hay ciclo
        }
        return false;                            // la liebre llego al final
        // <<< FIN TODO 3 <<<
    }   // Complejidad: O(n) tiempo, O(1) espacio
};

int main() {
    ListaSimple<int> L;
    for (int v : {40, 30, 20, 10}) L.insertarFrente(v);   // arma 10->20->30->40
    std::cout << "Inicial:             "; L.imprimir();

    L.insertarFrente(5);  std::cout << "Op1 insertarFrente(5): "; L.imprimir();
    L.insertarFinal(50);  std::cout << "Op2 insertarFinal(50): "; L.imprimir();
    L.eliminar(20);       std::cout << "Op3 eliminar(20):      "; L.imprimir();
    L.invertir();         std::cout << "Op4 invertir():        "; L.imprimir();

    L.eliminar(999);      std::cout << "eliminar(999) (no existe): "; L.imprimir();

    std::cout << "\ntieneCiclo() sin ciclo: " << std::boolalpha << L.tieneCiclo() << "\n";
    L.crearCicloPrueba();
    std::cout << "tieneCiclo() con ciclo: " << L.tieneCiclo() << "\n";
    L.romperCicloPrueba();                    // para que el destructor no se cuelgue
    return 0;
}
