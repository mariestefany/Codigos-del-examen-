# SIS210 – Algoritmos y Estructuras de Datos · Examen Parcial (Unidad I)

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![Compilador](https://img.shields.io/badge/g%2B%2B-13-green.svg)

Códigos en C++17 que comprueban las respuestas del Examen Parcial de la Unidad I.

- **Universidad:** Universidad Nacional del Altiplano (UNAP), Puno – Perú
- **Escuela:** Ingeniería de Sistemas
- **Curso:** SIS210 – Algoritmos y Estructuras de Datos (2026-II)
- **Docente:** Mg. Aldo Hernán Zanabria Gálvez
- **Autora:** Marie

---

## Contenido

| Archivo | Pregunta | Tema |
|---|---|---|
| [`src/p1_1_misterio.cpp`](src/p1_1_misterio.cpp) | 1.1 | Análisis de complejidad: conteo de comparaciones e inversiones |
| [`src/p1_2_insertion.cpp`](src/p1_2_insertion.cpp) | 1.2 | Traza de Insertion Sort |
| [`src/p2_lista.cpp`](src/p2_lista.cpp) | 2.1 y 2.2 | Lista simple: `eliminar`, `invertir`, `tieneCiclo` (Floyd) |
| [`src/p3_1_postfija.cpp`](src/p3_1_postfija.cpp) | 3.1 | Evaluación de expresión postfija con pila |
| [`src/p3_2_cola_circular.cpp`](src/p3_2_cola_circular.cpp) | 3.2 | Cola circular con arreglo: `estaLlena`, `dequeue` |
| [`src/p4_hash.cpp`](src/p4_hash.cpp) | 5.1 | Tabla hash con sondeo lineal |

## Estructura sugerida del repositorio

```
.
├── README.md
├── informe/
│   └── Informe_SIS210_Examen_UnidadI.pdf
└── src/
    ├── p1_1_misterio.cpp
    ├── p1_2_insertion.cpp
    ├── p2_lista.cpp
    ├── p3_1_postfija.cpp
    ├── p3_2_cola_circular.cpp
    └── p4_hash.cpp
```

## Requisitos

- Un compilador con soporte de **C++17** (`g++` 7 o superior, `clang++` o MSVC reciente).
- No se usan librerías externas, solo la biblioteca estándar.

## Cómo compilar y ejecutar

### Un programa

```bash
g++ -std=c++17 -Wall -Wextra -o p1_1 src/p1_1_misterio.cpp
./p1_1
```

En Windows (PowerShell) el ejecutable se llama `p1_1.exe`:

```powershell
g++ -std=c++17 -Wall -Wextra -o p1_1 src/p1_1_misterio.cpp
.\p1_1.exe
```

### Todos a la vez (Linux / macOS / Git Bash)

```bash
mkdir -p build
for f in src/*.cpp; do
  nombre=$(basename "$f" .cpp)
  g++ -std=c++17 -Wall -Wextra -o "build/$nombre" "$f" && echo "=== $nombre ===" && "./build/$nombre"
done
```

### Sin instalar nada (compiladores en línea)

Abre uno de estos, pega el contenido del `.cpp`, elige **C++17** y pulsa *Run*:

- [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler)
- [Programiz](https://www.programiz.com/cpp-programming/online-compiler/)
- [Compiler Explorer](https://godbolt.org/)

## Código de colores / marcadores en los archivos

Dentro de cada `.cpp` hay comentarios que delimitan qué es respuesta y qué es ayuda para probar:

| Marcador | Significado |
|---|---|
| `// >>> RESPUESTA ... >>>` … `// <<< FIN <<<` | Código que se completa en el examen (los TODO) |
| `// >>> AGREGADO ... >>>` … `// <<< FIN <<<` | Código agregado solo para comprobar un resultado |
| `// >>> AUXILIAR ... >>>` … `// <<< FIN AUXILIAR <<<` | Funciones de apoyo para imprimir o probar; **no** van en la respuesta del examen |

## Descripción y salida esperada

### 1.1 · `p1_1_misterio.cpp`
Cuenta cuántas veces se ejecuta la comparación `A[i] > A[j]` y compara con n(n−1)/2.

```
Mejor  (ordenado) -> retorna 0 | comparaciones = 15 | n(n-1)/2 = 15
Peor   (inverso)  -> retorna 15 | comparaciones = 15 | n(n-1)/2 = 15
Normal (mezclado) -> retorna 9 | comparaciones = 15 | n(n-1)/2 = 15
```

Las comparaciones son siempre n(n−1)/2 (Θ(n²)); lo que cambia es el valor retornado (número de inversiones).

### 1.2 · `p1_2_insertion.cpp`
Traza de Insertion Sort sobre `[38, 15, 27, 5, 42, 11]`, con el arreglo y las comparaciones de cada pasada.

```
Total comparaciones: 12
```

### 2.1 y 2.2 · `p2_lista.cpp`
Lista simple genérica `ListaSimple<T>` con:

| Método | Tiempo | Espacio |
|---|---|---|
| `eliminar(val)` | O(n) | O(1) |
| `invertir()` | O(n) | O(1) |
| `tieneCiclo()` (Floyd, tortuga y liebre) | O(n) | O(1) |

`main` ejecuta las operaciones del enunciado:

```
Inicial:             10 -> 20 -> 30 -> 40 -> nullptr  (tam=4)
Op1 insertarFrente(5): 5 -> 10 -> 20 -> 30 -> 40 -> nullptr  (tam=5)
Op2 insertarFinal(50): 5 -> 10 -> 20 -> 30 -> 40 -> 50 -> nullptr  (tam=6)
Op3 eliminar(20):      5 -> 10 -> 30 -> 40 -> 50 -> nullptr  (tam=5)
Op4 invertir():        50 -> 40 -> 30 -> 10 -> 5 -> nullptr  (tam=5)
```

Además prueba `eliminar` de un valor inexistente y `tieneCiclo()` con y sin ciclo (`false` / `true`).

### 3.1 · `p3_1_postfija.cpp`
Evalúa `8 3 4 * + 2 / 5 -` con `std::stack`, mostrando cada token.

```
Resultado final: 5
Operandos: 5, operadores: 4, total tokens: 9
```

Detalle importante: el **primer** `pop` es el operando derecho (por eso `20 / 2` y no `2 / 20`).

### 3.2 · `p3_2_cola_circular.cpp`
`ColaCircular<T, CAP>` con `estaLlena()` y `dequeue()`. Traza con `CAP = 4`:
`enqueue(1)`, `enqueue(2)`, `enqueue(3)`, `dequeue()`, `enqueue(4)`, `dequeue()`.

```
dequeue()   | frente=1 final_=3 tam=2 ... retorna=1
enqueue(4)  | frente=1 final_=0 tam=3 datos=[1,2,3,4]
dequeue()   | frente=2 final_=0 tam=2 ... retorna=2
```

En `enqueue(4)`, `final_ = (3 + 1) % 4 = 0`: ahí se ve lo "circular".

### 5.1 · `p4_hash.cpp`
Inserta `22, 33, 44, 55, 18, 29` con `h(k) = k mod 11` y sondeo lineal `h(k,i) = (h(k)+i) mod 11`.

```
Slot: 0   1   2   3   4   5   6   7   8   9   10
Val : 22  33  44  55  -   -   -   18  29  -   -
Factor de carga alpha = 6/11 = 0.545455
```

Las claves 22, 33, 44 y 55 forman un bloque contiguo: eso es el **clustering primario**.

## Notas

- Todos los programas compilan sin advertencias con `-std=c++17 -Wall -Wextra`.
- En `p3_2_cola_circular.cpp` el arreglo se inicializa con `= {}` (marcado como auxiliar) solo para que las celdas libres se muestren como `0` en la traza.
- En `p2_lista.cpp`, `crearCicloPrueba()` y `romperCicloPrueba()` existen solo para poder probar `tieneCiclo()` sin dejar un bucle infinito al destruir la lista.

## Subir a GitHub

```bash
git init
git add .
git commit -m "Solución examen parcial SIS210 - Unidad I"
git branch -M main
git remote add origin https://github.com/<tu-usuario>/<tu-repositorio>.git
git push -u origin main
```

## Licencia

Uso académico. Si quieres abrirlo al público, agrega un archivo `LICENSE` (por ejemplo MIT).
