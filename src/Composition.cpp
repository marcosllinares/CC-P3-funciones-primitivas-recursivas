/**
 * @file Composition.cpp
 * @brief Implementación de la operación de composición de funciones
 */

#include "../include/Composition.hpp"

Composition::Composition(std::shared_ptr<PrimitiveFunction> g, 
                         std::vector<std::shared_ptr<PrimitiveFunction>> h_functions) 
    : g_(g), h_functions_(h_functions), call_count_(0) {}

/**
 * @brief Composición: f(x_1, ..., x_n) = g(h_1(x_1, ..., x_n), ..., h_m(x_1, ..., x_n))
 */
unsigned int Composition::evaluate(const std::vector<unsigned int>& args) {
  call_count_++;
  
  std::vector<unsigned int> h_results;
  for (auto& h : h_functions_) {
    h_results.push_back(h->evaluate(args));
  }
  
  return g_->evaluate(h_results);
}

void Composition::resetCallCounter() {
  call_count_ = 0;
  g_->resetCallCounter();
  for (auto& h : h_functions_) {
    h->resetCallCounter();
  }
}

unsigned int Composition::getCallCount() const {
  unsigned int total = call_count_;
  total += g_->getCallCount();
  for (auto& h : h_functions_) {
    total += h->getCallCount();
  }
  return total;
}
