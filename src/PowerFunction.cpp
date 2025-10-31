/**
 * @file PowerFunction.cpp
 * @brief Implementación de la función potencia como función primitiva recursiva
 */

#include "../include/PowerFunction.hpp"
#include "../include/InitialFunctions.hpp"
#include "../include/PrimitiveRecursion.hpp"
#include "../include/Composition.hpp"
#include "../include/Projection.hpp"
#include "../include/ArithmeticFunctions.hpp"

/**
 * @brief Potencia: power(x, 0) = 1
 *                  power(x, y+1) = mult(x, power(x, y))
 * 
 * Para el caso base necesitamos una función que devuelva 1 (el sucesor de cero)
 */
Power::Power() {
  auto zero = std::make_shared<Zero>();
  auto succ = std::make_shared<Successor>();
  auto f = std::make_shared<Composition>(succ, std::vector<std::shared_ptr<PrimitiveFunction>>{zero});
  
  auto mult = std::make_shared<Multiplication>();
  auto proj_x = std::make_shared<Projection>(0);
  auto proj_result = std::make_shared<Projection>(2);
  auto g = std::make_shared<Composition>(mult, std::vector<std::shared_ptr<PrimitiveFunction>>{proj_x, proj_result});
  
  impl_ = std::make_shared<PrimitiveRecursion>(f, g);
}

unsigned int Power::evaluate(const std::vector<unsigned int>& args) {
  return impl_->evaluate(args);
}

void Power::resetCallCounter() {
  impl_->resetCallCounter();
}

unsigned int Power::getCallCount() const {
  return impl_->getCallCount();
}
