// system includes
#include <assert.h>
#include <cstdint>
#include <iostream>

int main(int /*argc*/, char** /*argv*/)
{
  try
  {
    std::cout << "Hello World" << std::endl;
  }
    catch (std::exception& e)
  {
    std::cout << "[exception] " << e.what() << std::endl;
    assert(false);
  }

  //  std::cout << imp::ok_msg << std::endl;
  return EXIT_SUCCESS;
}
