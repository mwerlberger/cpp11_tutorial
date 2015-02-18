#include <iostream>

namespace old
{
enum PixelType
{
  i8uC1,
  i8uC3,
  i32fC1,
  i32fC3
};
}


namespace cpp11
{
enum class PixelType
{
  i8uC1,
  i8uC3,
  i32fC1,
  i32fC3
};
}

//==============================================================================
int main(int /*argc*/, char** /*argv*/)
{

  old::PixelType oldPxType = old::i8uC1;
  cpp11::PixelType cpp11PxType = cpp11::PixelType::i8uC1;


  /*
   * ... million lines of code
   */


  if (oldPxType == old::i8uC3)
  {
    std::cout << "3-channel image" << std::endl;
  }

  if (cpp11PxType == cpp11::PixelType::i8uC3)
  {
    std::cout << "3-channel image" << std::endl;
  }

  return EXIT_SUCCESS;
}

