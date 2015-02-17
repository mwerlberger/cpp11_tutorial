
// system includes
#include <assert.h>
#include <cstdint>
#include <iostream>
#include <memory>

#include "override_class.hpp"
#include "override_class_old.hpp"

// TA <- TB <- TC

template <class TA, class TB, class TC>
void testClass()
{
  std::unique_ptr<TA> a(new TA());
  std::unique_ptr<TA> b(new TB());
  std::unique_ptr<TA> c(new TC());

  std::cout << "a: " << a->get() << std::endl;
  std::cout << "b: " << b->get() << std::endl;
  std::cout << "c: " << c->get() << std::endl;
}

int main(int /*argc*/, char** /*argv*/)
{
  try
  {
    std::cout << "Old:" << std::endl;
    testClass<AOld, BOld, COld>();
    std::cout << std::endl;

    std::cout << "New:" << std::endl;
    testClass<A, B, C>();
    std::cout << std::endl;
  }
  catch (std::exception& e)
  {
    std::cout << "[exception] " << e.what() << std::endl;
    assert(false);
  }

  //  std::cout << imp::ok_msg << std::endl;
  return EXIT_SUCCESS;
}

