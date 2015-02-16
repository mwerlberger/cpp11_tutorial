#ifndef USING_CLASS_OLD_HPP
#define USING_CLASS_OLD_HPP

#include <cstdint>

//------------------------------------------------------------------------------
class UsingBaseOld
{
public:
  UsingBaseOld()
    : a_(0)
    , b_(0.0)
  {
  }

  virtual ~UsingBaseOld()
  {
  }

  UsingBaseOld(std::int32_t a)
    : a_(a)
    , b_(0.0)
  {
  }

  UsingBaseOld(double b)
    : b_(b)
  {
  }

  inline std::int32_t a() {return a_;}
  inline double b() {return b_;}

protected:
  std::int32_t a_;
  double b_;

};


//------------------------------------------------------------------------------
class UsingDerivedOld : public UsingBaseOld
{
public:
  UsingDerivedOld()
    : UsingBaseOld()
  {
  }

  virtual ~UsingDerivedOld()
  {
  }

  UsingDerivedOld(std::int32_t a)
    : UsingBaseOld(a)
  {
  }

  UsingDerivedOld(double b)
    : UsingBaseOld(b)
  {
  }

  UsingDerivedOld(std::int32_t a, double b)
    : UsingBaseOld()
  {
    a_ = a;
    b_ = b;
  }

};

#endif // USING_CLASS_OLD_HPP

