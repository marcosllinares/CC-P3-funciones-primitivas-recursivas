# Práctica 03 - Funciones Primitivas Recursivas
Práctica que implementa la función potencia como una función primitiva recursiva.

Enlace al repositorio: [https://github.com/marcosllinares/CC-P2-maquina-turing](https://github.com/marcosllinares/CC-P2-maquina-turing)

Autor: Trabajo realizado por Marcos Llinares Montes (alu0100972443)

**Características de implementación**
- Implementación de **funciones recursivas iniciales**: Zero, Successor, Projection
- Operaciones de **composición** y **recursión primitiva**
- Funciones aritméticas: **suma** y **multiplicación** como funciones primitivas recursivas
- Función **potencia** (x^y) construida usando recursión primitiva
- **Contador de llamadas** a funciones para análisis de complejidad
- **Validación de entrada**: solo acepta números naturales (N)
- Diseño **orientado a objetos** con jerarquía de clases

**Definiciones matemáticas:**

**Funciones recursivas iniciales:**
```
Zero:       Z(x) = 0
Successor:  S(x) = x + 1
Projection: P_i(x_1, ..., x_n) = x_i
```

**Suma (usando recursión primitiva):**
```
add(x, 0)   = x
add(x, y+1) = S(add(x, y))
```

**Multiplicación (usando recursión primitiva):**
```
mult(x, 0)   = 0
mult(x, y+1) = add(x, mult(x, y))
```

**Potencia (usando recursión primitiva):**
```
power(x, 0)   = 1
power(x, y+1) = mult(x, power(x, y))
```


## Estructura del proyecto
- `include/` : cabeceras (.hpp)
- `src/`     : implementación (.cpp)
- `build/`, `bin/` : artefactos de compilación (creados por `make`)

```
.
├── Makefile
├── README.md
├── bin/
│   └── primitive-recursion
├── build/
│   └── *.o, *.d
├── include/
│   ├── ArithmeticFunctions.hpp
│   ├── Composition.hpp
│   ├── InitialFunctions.hpp
│   ├── PowerFunction.hpp
│   ├── PrimitiveFunction.hpp
│   ├── PrimitiveRecursion.hpp
│   └── Projection.hpp
└── src/
    ├── ArithmeticFunctions.cpp
    ├── Composition.cpp
    ├── InitialFunctions.cpp
    ├── main.cpp
    ├── PowerFunction.cpp
    └── PrimitiveRecursion.cpp
```


## Compilación
El proyecto se compila mediante `make` (Makefile incluido). Basta ejecutar desde la raíz del proyecto:

```sh
make
```

El binario resultante es `bin/primitive-recursion`

Para limpiar los archivos compilados:

```sh
make clean
```

## Ejecución
Uso básico:

```sh
./bin/primitive-recursion [base] [exponente]
```

**Modo 1: Con parámetros por línea de comandos**

```sh
./bin/primitive-recursion 2 5
```

**Modo 2: Entrada interactiva** (sin parámetros)

```sh
./bin/primitive-recursion
```

El programa solicitará la base y el exponente.

**Validación de entrada:**
- Solo acepta **números naturales** (enteros >= 0)
- Rechaza números negativos, decimales y caracteres no numéricos
- En modo interactivo, solicita nuevamente el valor si es inválido
- En modo línea de comandos, muestra error y termina

**Ejemplos de ejecución:**

```sh
# Entrada válida
$ ./bin/primitive-recursion 2 5

Resultado: 2^5 = 32
Número de llamadas a funciones: 1114

# Entrada inválida
$ ./bin/primitive-recursion -3 5
Error: Los argumentos deben ser números naturales (enteros >= 0)

# Casos especiales
$ ./bin/primitive-recursion 0 0
Resultado: 0^0 = 1
Número de llamadas a funciones: 4

$ ./bin/primitive-recursion 3 4
Resultado: 3^4 = 81
Número de llamadas a funciones: 3734
```
