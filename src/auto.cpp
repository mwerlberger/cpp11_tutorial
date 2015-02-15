// system includes
#include <assert.h>
#include <cstdint>
#include <iostream>
#include <cmath>

#include "helpers.hpp"

//------------------------------------------------------------------------------
decltype(auto) getVal() // only c++14
{
  double pi=M_PI;
  return pi;
}

//==============================================================================
int main(int /*argc*/, char** /*argv*/)
{
  try
  {
    std::cout << "keyword auto:" << std::endl << std::endl;

    auto x=123;
    const auto xx = x;
    auto& ref_x = x;
    ref_x = 321;
    
    std::cout
        << "x: " << x << std::endl
        << "xx: " << xx << std::endl
        << "ref_x: " << ref_x << std::endl
        << std::endl;

    auto px = &x;
    auto* ppx = &x;

    *ppx = 1122;

    std::cout
        << "px: " << *px << std::endl
        << "ppx: " << *ppx << std::endl
        << std::endl;

    auto val = getVal();
    std::cout
        << "val: " << val << std::endl
        << "val type: " << type_name<decltype(val)>() << std::endl
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
