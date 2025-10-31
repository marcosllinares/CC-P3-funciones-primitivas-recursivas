# Práctica 03 - Funciones Primitivas Recursivas
Práctica que implementa la función potencia como una función primitiva recursiva.

Enlace al repositorio: [https://github.com/marcosllinares/CC-P3-funciones-primitivas-recursivas](https://github.com/marcosllinares/CC-P3-funciones-primitivas-recursivas)

Autor: Trabajo realizado por Marcos Llinares Montes (alu0100972443)

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

## Contador de Llamadas a Funciones

El programa implementa un sistema de conteo de llamadas para analizar la complejidad computacional:

**Funcionamiento:**
- Cada función primitiva (Zero, Successor, Projection, Composition, PrimitiveRecursion) mantiene un contador interno
- Cada vez que se ejecuta el método `evaluate()` de cualquier función, se incrementa su contador
- Las operaciones compuestas (Composition, PrimitiveRecursion) acumulan:
  - Sus propias llamadas directas
  - Las llamadas de todas las subfunciones que invocan

**Ejemplo de conteo para `power(2, 3) = 8`:**
```
power(2, 3) llama a:
  - PrimitiveRecursion (1 llamada)
    - Para y=0: llama a f (caso base)
    - Para y=1,2,3: llama a g (paso recursivo) que es mult(x, prev_result)
      - mult llama a PrimitiveRecursion
        - Para cada multiplicación: múltiples llamadas a add
          - add llama a PrimitiveRecursion
            - Para cada suma: múltiples llamadas a Successor
```

**Conteo total:**
El método `getCallCount()` recursivamente suma:
1. Llamadas propias de la función
2. Llamadas de todas las funciones que utiliza (composición, recursión)
3. Llamadas de las funciones primitivas iniciales (Zero, Successor, Projection)

Esto proporciona una medida exacta del número total de evaluaciones de funciones necesarias para calcular el resultado.
