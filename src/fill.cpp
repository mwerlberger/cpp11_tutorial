#include <assert.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>

#include "helpers.hpp"

//==============================================================================
int main(int /*argc*/, char** /*argv*/)
{
  try
  {
    int length = 10;

    std::uint8_t pixels_8u[length];
    std::uint16_t pixels_16u[length];

    memset(pixels_8u,  1, length*sizeof(std::uint8_t));
    memset(pixels_16u, 1, length*sizeof(std::uint16_t));

    std::cout << "using memset:" << std::endl;
    for (auto px : pixels_8u)
    {
      std::cout << static_cast<std::int32_t>(px) << " ";
    }
    std::cout << std::endl;

    for (auto px : pixels_16u)
    {
      std::cout << static_cast<std::int32_t>(px) << " ";
    }
    std::cout << std::endl << std::endl;

    // use std::fill
    std::fill(pixels_8u, pixels_8u+length, 1);
    std::fill(pixels_16u, pixels_16u+length, 1);

    std::cout << "using std::fill:" << std::endl;
    for (auto px : pixels_8u)
    {
      std::cout << static_cast<std::int32_t>(px) << " ";
    }
    std::cout << std::endl;

    for (auto px : pixels_16u)
    {
      std::cout << static_cast<std::int32_t>(px) << " ";
    }
    std::cout << std::endl;


  }
    catch (std::exception& e)
  {
    std::cout << "[exception] " << e.what() << std::endl;
    assert(false);
  }


  return EXIT_SUCCESS;
}

