#ifndef POWER_FUNCTION_HPP
#define POWER_FUNCTION_HPP

#include "PrimitiveFunction.hpp"
#include <memory>

class Power : public PrimitiveFunction {
private:
  std::shared_ptr<PrimitiveFunction> impl_;

public:
  Power();
  unsigned int evaluate(const std::vector<unsigned int>& args) override;
  void resetCallCounter() override;
  unsigned int getCallCount() const override;
};

#endif
