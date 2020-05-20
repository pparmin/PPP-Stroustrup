#include "my.h"
#include <iostream>

int foo;

void print_foo() 
{
  std::cout << foo << '\n';
}

void print(int i) 
{
  std::cout << i << '\n';
}

void swap_v(int a, int b) 
{
  std::cout << "VALUES BEFORE SWAP: " << a << b << std::endl;
  int temp; 
  temp = a;   // copy value of a to temp
  a = b;      // copy value of b to a
  b = temp;   // copy value of temp to b
  std::cout << "VALUES AFTER SWAP: " << a << b << std::endl;
}

void swap_r(int& a, int& b) 
{
  std::cout << "VALUES BEFORE SWAP: " << a << b << std::endl;
  int temp; 
  temp = a;   // copy value of a to temp
  a = b;      // copy value of b to a
  b = temp;   // copy value of temp to b
  std::cout << "VALUES AFTER SWAP: " << a << b << std::endl;
}

// void swap_cr(const int& a, const int& b) 
// {
//   int temp; 
//   temp = a;   // copy value of a to temp
//   a = b;      // copy value of b to a
//   b = temp;   // copy value of temp to b
// }
