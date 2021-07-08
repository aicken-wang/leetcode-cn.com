//
//  main.cpp
//  algotest
//
//  Created by shunqing wang on 2021/6/28.
//

#include <algorithm>
#include <random>
#include <string>
#include <vector>

int main()
{
  std::vector<std::string> vec;
  std::mt19937_64 gen(43);

  for (int count = 0; count < 3; ++count)
  {
    for (int i = 0; i < 10 * 1000 * 1000; ++i)
    {
      char buf[64];
      snprintf(buf, sizeof buf, "%016", gen());
      vec.push_back(buf);
    }
    std::sort(vec.begin(), vec.end());  // 如果用 tcmalloc 2.5，这行注释掉反而会变慢！
    vec.clear();
  }
}
