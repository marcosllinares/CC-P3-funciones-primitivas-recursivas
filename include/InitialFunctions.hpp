#ifndef INITIAL_FUNCTIONS_HPP
#define INITIAL_FUNCTIONS_HPP

#include "PrimitiveFunction.hpp"

class Zero : public PrimitiveFunction {
private:
  unsigned int call_count_;

public:
  Zero();
  unsigned int evaluate(const std::vector<unsigned int>& args) override;
  void resetCallCounter() override;
  unsigned int getCallCount() const override;
};

class Successor : public PrimitiveFunction {
private:
  unsigned int call_count_;

public:
  Successor();
  unsigned int evaluate(const std::vector<unsigned int>& args) override;
  void resetCallCounter() override;
  unsigned int getCallCount() const override;
};

class Projection : public PrimitiveFunction {
private:
  unsigned int index_;
  unsigned int call_count_;

public:
  Projection(unsigned int index);
  unsigned int evaluate(const std::vector<unsigned int>& args) override;
  void resetCallCounter() override;
  unsigned int getCallCount() const override;
};

#endif
