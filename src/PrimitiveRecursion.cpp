/**
 * @file PrimitiveRecursion.cpp
 * @brief Implementación de la operación de recursión primitiva
 */

#include "../include/PrimitiveRecursion.hpp"

PrimitiveRecursion::PrimitiveRecursion(std::shared_ptr<PrimitiveFunction> f, 
                                       std::shared_ptr<PrimitiveFunction> g) 
    : f_(f), g_(g), call_count_(0) {}

/**
 * @brief Recursión primitiva:
 * h(x, 0) = f(x)
 * h(x, y+1) = g(x, y, h(x,y))
 */
unsigned int PrimitiveRecursion::evaluate(const std::vector<unsigned int>& args) {
  call_count_++;
  
  if (args.empty()) return 0;
  
  unsigned int y = args.back();
  std::vector<unsigned int> x_args(args.begin(), args.end() - 1);
  
  if (y == 0) {
    return f_->evaluate(x_args);
  }
  
  unsigned int prev_result = f_->evaluate(x_args);
  
  for (unsigned int i = 0; i < y; i++) {
    std::vector<unsigned int> g_args = x_args;
    g_args.push_back(i);
    g_args.push_back(prev_result);
    prev_result = g_->evaluate(g_args);
  }
  
  return prev_result;
}

void PrimitiveRecursion::resetCallCounter() {
  call_count_ = 0;
  f_->resetCallCounter();
  g_->resetCallCounter();
}

unsigned int PrimitiveRecursion::getCallCount() const {
  return call_count_ + f_->getCallCount() + g_->getCallCount();
}
