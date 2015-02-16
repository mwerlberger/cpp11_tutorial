#ifndef OVERRIDE_CLASS_OLD_HPP
#define OVERRIDE_CLASS_OLD_HPP

#include <string>

class AOld
{
public:
  AOld() = default;
  virtual ~AOld() = default;

  std::string get() {return std::string("A");}
};

class BOld : public AOld
{
public:
  BOld() = default;
  virtual ~BOld() = default;

  virtual std::string get() {return std::string("B");}
};

class COld : public BOld
{
public:
  COld() = default;
  virtual ~COld() = default;

  virtual std::string get() {return std::string("C");}
};


#endif // OVERRIDE_CLASS_OLD_HPP

