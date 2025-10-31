/**
 * @file ArithmeticFunctions.cpp
 * @brief Implementación de funciones aritméticas como funciones primitivas recursivas
 */

#include "../include/ArithmeticFunctions.hpp"
#include "../include/InitialFunctions.hpp"
#include "../include/PrimitiveRecursion.hpp"
#include "../include/Composition.hpp"
#include "../include/Projection.hpp"

/**
 * @brief Suma: add(x, 0) = x
 *              add(x, y+1) = S(add(x, y))
 */
Addition::Addition() {
  auto f = std::make_shared<Projection>(0);
  
  auto succ = std::make_shared<Successor>();
  auto proj_result = std::make_shared<Projection>(2);
  auto g = std::make_shared<Composition>(succ, std::vector<std::shared_ptr<PrimitiveFunction>>{proj_result});
  
  impl_ = std::make_shared<PrimitiveRecursion>(f, g);
}

unsigned int Addition::evaluate(const std::vector<unsigned int>& args) {
  return impl_->evaluate(args);
}

void Addition::resetCallCounter() {
  impl_->resetCallCounter();
}

unsigned int Addition::getCallCount() const {
  return impl_->getCallCount();
}

/**
 * @brief Multiplicación: mult(x, 0) = 0
 *                        mult(x, y+1) = add(x, mult(x, y))
 */
Multiplication::Multiplication() {
  auto f = std::make_shared<Zero>();
  
  auto add = std::make_shared<Addition>();
  auto proj_x = std::make_shared<Projection>(0);
  auto proj_result = std::make_shared<Projection>(2);
  auto g = std::make_shared<Composition>(add, std::vector<std::shared_ptr<PrimitiveFunction>>{proj_x, proj_result});
  
  impl_ = std::make_shared<PrimitiveRecursion>(f, g);
}

unsigned int Multiplication::evaluate(const std::vector<unsigned int>& args) {
  return impl_->evaluate(args);
}

void Multiplication::resetCallCounter() {
  impl_->resetCallCounter();
}

unsigned int Multiplication::getCallCount() const {
  return impl_->getCallCount();
}
