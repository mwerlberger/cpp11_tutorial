#include <assert.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <array>
#include <cstring>

namespace old
{
class A
{
public:
  A() {init(13);}
  A(int i) {init(i);}

  int i() {return i_;}

private:
  void init(int i) {i_=i;}
  int i_;
};
}


namespace cpp11
{
class A
{
public:
  A() : A(13) {}
  A(int i) : i_(i) {}

  int i() {return i_;}

private:
  int i_;
};
}


//==============================================================================
int main(int /*argc*/, char** /*argv*/)
{
  try
  {
    old::A old1;
    old::A old2(14);

    cpp11::A new1;
    cpp11::A new2(14);

    std::cout << "old: " << old1.i() << ", " << old2.i() << std::endl;
    std::cout << "new: " << new1.i() << ", " << new2.i() << std::endl;

  }
    catch (std::exception& e)
  {
    std::cout << "[exception] " << e.what() << std::endl;
    assert(false);
  }
  return EXIT_SUCCESS;
}

