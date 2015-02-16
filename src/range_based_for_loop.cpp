#include <iostream>
#include <vector>

int main()
{
  std::vector<int> ivec = {0, 1, 2, 3, 4, 5};

  for (auto i : ivec)
  {
    std::cout << i << ", ";
  }
  std::cout << std::endl;


  for(auto j : {0,2,4,6,8,10})
  {
    std::cout << j << ", ";
  }
  std::cout << std::endl;
}
