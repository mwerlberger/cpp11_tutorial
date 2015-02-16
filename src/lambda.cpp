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
    std::vector<std::uint8_t> pixels { 128, 13, 14, 11, 129, 200, 214, 252, 254 };

    for (const auto& px : pixels)
    {
      std::cout << std::setfill('0') << std::setw(3)
                << static_cast<int>(px) << " ";
    }
    std::cout << std::endl;

    int threshold = 128;
    std::for_each(pixels.begin(), pixels.end(),
                 [threshold](auto& px)
    {
      if(px<threshold)
        px=0;
    });

    std::for_each(pixels.begin(), pixels.end(),
                  [](const auto& px)
    {
      std::cout << std::setfill('0') << std::setw(3)
                << static_cast<int>(px) << " ";
    });
    std::cout << std::endl;

  }
    catch (std::exception& e)
  {
    std::cout << "[exception] " << e.what() << std::endl;
    assert(false);
  }

  return EXIT_SUCCESS;
}

