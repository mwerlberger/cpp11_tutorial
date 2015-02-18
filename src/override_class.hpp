#ifndef OVERRIDE_CLASS_HPP
#define OVERRIDE_CLASS_HPP

#include <string>

class A
{
public:
  A() = default;
  virtual ~A() = default;

  virtual std::string get() {return std::string("A");}
};

class B : public A
{
public:
  B() = default;
  virtual ~B() = default;

  virtual std::string get() override {return std::string("B");}
};

class C : public B
{
public:
  C() = default;
  virtual ~C() = default;

  virtual std::string get() final {return std::string("C");}
};


#endif // OVERRIDE_CLASS_HPP

