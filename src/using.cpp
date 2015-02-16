// system includes
#include <assert.h>
#include <cstdint>
#include <iostream>

#include "using_class.hpp"
#include "using_class_old.hpp"


template <class TBase, class TDerived>
void testClass()
{
  TBase base;
  TBase base_i(11);
  TBase base_d(13.3);

  std::cout << "base  : " << base.a() << ", " << base.b() << std::endl;
  std::cout << "base_i: " << base_i.a() << ", " << base_i.b() << std::endl;
  std::cout << "base_d: " << base_d.a() << ", " << base_d.b() << std::endl;


  TDerived derived;
  TDerived derived_i(11);
  TDerived derived_d(13.3);
  TDerived derived_id(11, 13.3);

  std::cout << "derived:    " << derived.a() << ", " << derived.b() << std::endl;
  std::cout << "derived_i:  " << derived_i.a() << ", " << derived_i.b() << std::endl;
  std::cout << "derived_d:  " << derived_d.a() << ", " << derived_d.b() << std::endl;
  std::cout << "derived_id: " << derived_id.a() << ", " << derived_id.b() << std::endl;
}

int main(int /*argc*/, char** /*argv*/)
{
  try
  {
    std::cout << "Old:" << std::endl;
    testClass<UsingBaseOld, UsingDerivedOld>();
    std::cout << std::endl;

    std::cout << "New:" << std::endl;
    testClass<UsingBase, UsingDerived>();
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

