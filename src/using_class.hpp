#ifndef USING_CLASSHPP
#define USING_CLASSHPP

#include <cstdint>

//------------------------------------------------------------------------------
class UsingBase
{
public:
  UsingBase() = default;
  virtual ~UsingBase() = default;

  UsingBase(std::int32_t a)
    : a_(a)
  {
  }

  UsingBase(double b)
    : b_(b)
  {
  }

  inline std::int32_t a() {return a_;}
  inline double b() {return b_;}

protected:
  std::int32_t a_ = 0;
  double b_ = 0.0;

};


//------------------------------------------------------------------------------
class UsingDerived : public UsingBase
{
public:
  using Base = UsingBase;
  using Base::Base;

public:
  UsingDerived() = default;
  virtual ~UsingDerived() = default;

  UsingDerived(std::int32_t a, double b)
    : UsingBase()
  {
    a_ = a;
    b_ = b;
  }

};

#endif // USING_CLASSHPP

