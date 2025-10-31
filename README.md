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
