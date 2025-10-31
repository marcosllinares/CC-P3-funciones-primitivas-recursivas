#ifndef PRIMITIVE_RECURSION_HPP
#define PRIMITIVE_RECURSION_HPP

#include "PrimitiveFunction.hpp"
#include <memory>

class PrimitiveRecursion : public PrimitiveFunction {
private:
  std::shared_ptr<PrimitiveFunction> f_;
  std::shared_ptr<PrimitiveFunction> g_;
  unsigned int call_count_;

public:
  PrimitiveRecursion(std::shared_ptr<PrimitiveFunction> f, 
                     std::shared_ptr<PrimitiveFunction> g);
  unsigned int evaluate(const std::vector<unsigned int>& args) override;
  void resetCallCounter() override;
  unsigned int getCallCount() const override;
};

#endif
