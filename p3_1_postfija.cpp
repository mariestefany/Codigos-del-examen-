// SIS210 - Pregunta 3.1 - Evaluacion postfija con pila
// Compilar: g++ -std=c++17 -Wall -o p3_1 p3_1_postfija.cpp && ./p3_1
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

int main() {
    std::string expr = "8 3 4 * + 2 / 5 -";
    std::stack<int> pila;
    std::istringstream in(expr);
    std::string tok;
    int operandos = 0, operadores = 0;

    // >>> RESPUESTA: algoritmo de evaluacion postfija >>>
    while (in >> tok) {
        if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
            int b = pila.top(); pila.pop();      // 1er pop = operando DERECHO
            int a = pila.top(); pila.pop();      // 2do pop = operando IZQUIERDO
            int r = 0;
            if (tok == "+") r = a + b;
            else if (tok == "-") r = a - b;
            else if (tok == "*") r = a * b;
            else r = a / b;
            pila.push(r);
            ++operadores;
            std::cout << "token " << tok << " -> pop " << b << ", pop " << a
                      << " -> " << a << " " << tok << " " << b << " = " << r
                      << " -> tope = " << pila.top() << "\n";
        } else {
            pila.push(std::stoi(tok));
            ++operandos;
            std::cout << "token " << tok << " -> push(" << tok << ") -> tope = "
                      << pila.top() << "\n";
        }
    }
    // <<< FIN <<<
    std::cout << "Resultado final: " << pila.top() << "\n";
    std::cout << "Operandos: " << operandos << ", operadores: " << operadores
              << ", total tokens: " << operandos + operadores << "\n";
    return 0;
}
