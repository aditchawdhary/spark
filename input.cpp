#include <iostream>
// #include <string>

int main() {
  std::cout << "what is your name?" << std::endl;
  std::string name;
  std::cin >> name;
  std::cout << "welcome to c++ world, " << name << "!" << std::endl;
  return 0;
}