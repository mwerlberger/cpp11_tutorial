// system includes
#include <assert.h>
#include <cstdint>
#include <iostream>

int main(int /*argc*/, char** /*argv*/)
{
  try
  {
    std::cout << "memory management" << std::endl;

    std::unique_ptr<int> a(new int(13));
    std::cout << "a: " << *a << std::endl;

    std::shared_ptr<int> b;
    std::cout << "b?: " << b << std::endl;
    b.reset(new int(*a));
    std::cout << "b?: " << b << std::endl;
    std::cout << "value of b: " << *b << std::endl;
  }
    catch (std::exception& e)
  {
    std::cout << "[exception] " << e.what() << std::endl;
    assert(false);
  }

  //  std::cout << imp::ok_msg << std::endl;
  return EXIT_SUCCESS;
}
