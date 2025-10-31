#ifndef ARITHMETIC_FUNCTIONS_HPP
#define ARITHMETIC_FUNCTIONS_HPP

#include "PrimitiveFunction.hpp"
#include <memory>

class Addition : public PrimitiveFunction {
private:
  std::shared_ptr<PrimitiveFunction> impl_;

public:
  Addition();
  unsigned int evaluate(const std::vector<unsigned int>& args) override;
  void resetCallCounter() override;
  unsigned int getCallCount() const override;
};

class Multiplication : public PrimitiveFunction {
private:
  std::shared_ptr<PrimitiveFunction> impl_;

public:
  Multiplication();
  unsigned int evaluate(const std::vector<unsigned int>& args) override;
  void resetCallCounter() override;
  unsigned int getCallCount() const override;
};

#endif
