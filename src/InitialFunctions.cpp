/**
 * @file InitialFunctions.cpp
 * @brief Implementación de las funciones recursivas iniciales
 */

#include "../include/InitialFunctions.hpp"

Zero::Zero() : call_count_(0) {}

/**
 * @brief Función constante cero Z(x) = 0
 */
unsigned int Zero::evaluate(const std::vector<unsigned int>&) {
  call_count_++;
  return 0;
}

void Zero::resetCallCounter() {
  call_count_ = 0;
}

unsigned int Zero::getCallCount() const {
  return call_count_;
}

Successor::Successor() : call_count_(0) {}

/**
 * @brief Función sucesor S(x) = x + 1
 */
unsigned int Successor::evaluate(const std::vector<unsigned int>& args) {
  call_count_++;
  if (args.empty()) return 1;
  return args[0] + 1;
}

void Successor::resetCallCounter() {
  call_count_ = 0;
}

unsigned int Successor::getCallCount() const {
  return call_count_;
}

Projection::Projection(unsigned int index) : index_(index), call_count_(0) {}

/**
 * @brief Función proyección P_i(x_1, ..., x_n) = x_i
 */
unsigned int Projection::evaluate(const std::vector<unsigned int>& args) {
  call_count_++;
  if (index_ >= args.size()) return 0;
  return args[index_];
}

void Projection::resetCallCounter() {
  call_count_ = 0;
}

unsigned int Projection::getCallCount() const {
  return call_count_;
}
