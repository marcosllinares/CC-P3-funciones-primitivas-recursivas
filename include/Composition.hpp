#ifndef COMPOSITION_HPP
#define COMPOSITION_HPP

#include "PrimitiveFunction.hpp"
#include <memory>

class Composition : public PrimitiveFunction {
private:
  std::shared_ptr<PrimitiveFunction> g_;
  std::vector<std::shared_ptr<PrimitiveFunction>> h_functions_;
  unsigned int call_count_;

public:
  Composition(std::shared_ptr<PrimitiveFunction> g, 
              std::vector<std::shared_ptr<PrimitiveFunction>> h_functions);
  unsigned int evaluate(const std::vector<unsigned int>& args) override;
  void resetCallCounter() override;
  unsigned int getCallCount() const override;
};

#endif
