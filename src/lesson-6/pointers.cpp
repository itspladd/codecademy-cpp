#include <iostream>

using namespace std;
// Oops I forgot to do files for the intervening lessons

int main() {
  // Pointer vars hold the actual memory address as a value
  int num = 50;
  string str = "beans";

  int* numPtr = &num;
  string* strPtr = &str;

  int* nullPointer = nullptr;

  cout << "int pointer: " << numPtr << "\n";
  cout << "str pointer: " << strPtr << "\n";
  cout << "value at int pointer: " << *numPtr << "\n";
  cout << "value at str pointer: " << *strPtr << "\n";
  cout << "null pointer: " << nullPointer << "\n";
  // Following line causes a seg fault! bc we're trying to get the value at a nonexistent memory location
  //cout << "value at null pointer: " << *nullPointer << "\n";
  
  // Also we can't do the following without casting the types, "operands are incompatible"
  // cout << "size of int pointer??" << (strPtr - numPtr) << "\n"
}