// system includes
#include <assert.h>
#include <cstdint>
#include <iostream>
#include <cmath>
#include <typeinfo>

#include "helpers.hpp"

//------------------------------------------------------------------------------
decltype(auto) getVal() // only c++14
{
  double pi=M_PI;
  return pi;
}

//------------------------------------------------------------------------------
const int* getInt(int& y) {return &y;}

//------------------------------------------------------------------------------
const int& getIntR(int& y) {return y;}

//==============================================================================
int main(int /*argc*/, char** /*argv*/)
{
  try
  {
    std::cout << "keyword auto:" << std::endl << std::endl;

    //------------------------------------------------------------------------------
    auto x=123; // x is an int
    const auto xx = x; // xx is a const int
    auto& ref_x = x; // ref_x is a int& to x
    ref_x = 321;

    std::cout
        << "x: " << x << std::endl
        << "xx: " << xx << std::endl
        << "ref_x: " << ref_x << std::endl
        << std::endl;

    //------------------------------------------------------------------------------
    auto px = &x; // px is a int*
    auto* ppx = &x; // ppx as well
    *ppx = 1122;

    int tmp = 3;
    auto rx = getInt(tmp);

    std::cout
        << "px: " << *px << std::endl
        << "ppx: " << *ppx << std::endl
        << "rx: " << *rx << "  (" << type_name<decltype(rx)>() << ")" << std::endl
        << std::endl;

    //------------------------------------------------------------------------------
    // remember int tmp = 3
    decltype(tmp) y = tmp;
    auto rrx = getIntR(y);
    ++rrx;

    std::cout
        << "y: " << y << "  (" << type_name<decltype(y)>() << ")" << std::endl
        << "rrx: " << rrx << "  (" << type_name<decltype(rrx)>() << ")" << std::endl
        << std::endl;

    //------------------------------------------------------------------------------
    auto val = getVal();
    std::cout
        << "val: " << val << "  (" << type_name<decltype(val)>() << ")" << std::endl
        << std::endl;

  }
    catch (std::exception& e)
  {
    std::cout << "[exception] " << e.what() << std::endl;
    assert(false);
  }

  //  std::cout << imp::ok_msg << std::endl;
  return EXIT_SUCCESS;
}
