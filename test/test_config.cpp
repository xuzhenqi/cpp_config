#include "cpp_config.h"
#include <iostream>
#include <cmath>

int main() {
  Config::Instance().LoadConfig("config");
  int i; Config::Instance().Parse("i", &i);
  float f; Config::Instance().Parse("f", &f);
  vector<int> is; Config::Instance().Parse("is", &is);
  string s; Config::Instance().Parse("s", &s);
  vector<string> ss; Config::Instance().Parse("ss", &ss);
  assert(i == 1);
  assert(fabs(f - 1.1) < 1e-5);
  assert(s == "va");
  assert(is.size() == 4);
  assert(is[0] == 1); assert(is[1] == 2);
  assert(is[2] == 5); assert(is[3] == 6);
  assert(ss.size() == 4);
  assert(ss[0] == "a"); assert(ss[1] == "b");
  assert(ss[2] == "c"); assert(ss[3] == "d");
  std::cout << Config::Instance().ListAll();  
  Config::Instance().Set("ss", "a,c,b,d");
  std::cout << Config::Instance().ListAll();  
  return 0;
}
