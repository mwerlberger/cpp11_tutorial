// system includes
#include <assert.h>
#include <cstdint>
#include <iostream>
#include <vector>
#include <future>
#include <cmath>

int main(int /*argc*/, char** /*argv*/)
{
  try
  {
    std::vector<int> values = {313222313, 123456789, 982451653,
                               941083987, 838041641, 131232414,
                               674506111, 694847533, 122949829};
    std::vector<std::future<bool>> futures;

    // check if the values are prime numbers
    // very simple / non-optimized
    // check copied from http://www.cplusplus.com/reference/future/async/
    for (const auto& val : values)
    {
      futures.push_back(std::async(std::launch::async,
                                   [](int in)
      {
        std::cout << "Checking if " << in << " is a prime number..." << std::endl;
        for (int i=2; i<in; ++i)
        {
          if (in%i==0)
          {
            return false;
          }
        }
        return true;
      }, val));
    }

    for (size_t i=0; i<values.size(); ++i)
    {
      std::cout << values.at(i) << " ";

      if (futures.at(i).get())
      {
        std::cout << "is prime";
      }
      else
      {
        std::cout << "is not prime";
      }
      std::cout << std::endl;
    }
  }
  catch (std::exception& e)
  {
    std::cout << "[exception] " << e.what() << std::endl;
    assert(false);
  }

  //  std::cout << imp::ok_msg << std::endl;
  return EXIT_SUCCESS;
}
