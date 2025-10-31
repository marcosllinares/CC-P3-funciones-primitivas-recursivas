/**
 * @file main.cpp
 * @brief Programa principal para calcular la función potencia como función primitiva recursiva
 */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "../include/PowerFunction.hpp"

/**
 * @brief Valida que una cadena represente un número natural
 */
bool isNaturalNumber(const std::string& str) {
  if (str.empty()) return false;
  
  for (char c : str) {
    if (!isdigit(c)) return false;
  }
  
  try {
    long long num = std::stoll(str);
    if (num < 0 || num > std::numeric_limits<unsigned int>::max()) {
      return false;
    }
  } catch (...) {
    return false;
  }
  
  return true;
}

/**
 * @brief Lee un número natural desde la entrada estándar
 */
unsigned int readNaturalNumber(const std::string& prompt) {
  std::string input;
  
  while (true) {
    std::cout << prompt;
    std::cin >> input;
    
    if (isNaturalNumber(input)) {
      return std::stoul(input);
    }
    
    std::cout << "Error: Debe introducir un número natural (entero >= 0)" << std::endl;
  }
}

int main(int argc, char* argv[]) {
  unsigned int x, y;
  
  if (argc == 3) {
    std::string arg1(argv[1]);
    std::string arg2(argv[2]);
    
    if (!isNaturalNumber(arg1) || !isNaturalNumber(arg2)) {
      std::cerr << "Error: Los argumentos deben ser números naturales (enteros >= 0)" << std::endl;
      return 1;
    }
    
    x = std::stoul(arg1);
    y = std::stoul(arg2);
  } else {
    x = readNaturalNumber("Introduce la base (x): ");
    y = readNaturalNumber("Introduce el exponente (y): ");
  }
  
  Power power;
  std::vector<unsigned int> args = {x, y};
  
  unsigned int result = power.evaluate(args);
  unsigned int call_count = power.getCallCount();
  
  std::cout << "\nResultado: " << x << "^" << y << " = " << result << std::endl;
  std::cout << "Número de llamadas a funciones: " << call_count << std::endl;
  
  return 0;
}
