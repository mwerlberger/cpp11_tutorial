// system includes
#include <assert.h>
#include <cstdint>
#include <iostream>
#include <vector>
#include <future>
#include <cmath>


void called_from_async() {
  std::cout << "Async call" << std::endl;
}

int main() {
  //called_from_async launched in a separate thread if possible
  std::future<void> result( std::async(called_from_async));

  std::cout << "Message from main." << std::endl;

  //ensure that called_from_async is launched synchronously
  //if it wasn't already launched
  result.get();

  return 0;
}



//int main(int /*argc*/, char** /*argv*/)
//{
//  try
//  {
//    std::vector<int> evens = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    std::vector<std::future<double>> futures;

//    // compute square of all values in evens
//    for (const auto& e : evens)
//    {
//      futures.push_back(std::async(std::launch::async, [](int in)
//      {return std::pow(2,in);} , e));
//    }

//    // print result values
//    for(auto& f : futures)
//    {
//      std::cout << f.get() << std::endl;
//    }
//  }
//  catch (std::exception& e)
//  {
//    std::cout << "[exception] " << e.what() << std::endl;
//    assert(false);
//  }

//  //  std::cout << imp::ok_msg << std::endl;
//  return EXIT_SUCCESS;
//}
