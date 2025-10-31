#ifndef PRIMITIVE_FUNCTION_HPP
#define PRIMITIVE_FUNCTION_HPP

#include <vector>
#include <memory>

class PrimitiveFunction {
public:
  virtual ~PrimitiveFunction() = default;
  virtual unsigned int evaluate(const std::vector<unsigned int>& args) = 0;
  virtual void resetCallCounter() = 0;
  virtual unsigned int getCallCount() const = 0;
};

#endif
