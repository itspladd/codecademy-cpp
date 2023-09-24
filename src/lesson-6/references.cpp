#include <iostream>

using namespace std;

/**
 * Triples the input by mutating it.
*/
int tripleRef(int &num) {
  num = num * 3;
  return num;
}

/**
 * Triples the input and returns the result without mutating it. 
*/
int triplePure(int const &num) {
  // We're not allocating new memory for &num to create a new variable, it's still a ref
  // BUT we're protected from mutating the ref value because of the const keyword!
  // So the following line would error out
  //num = num * 3;

  // And instead we do this
  return num * 3;
}

void printMemoryLocation(int &num, string const &name) {
  cout << "Memory location of input var " << name << ": " << &num << "\n";
}

int main() {
  // A reference is an alias for an existing variable
  // Similar to a pointer in a lot of the ways that matter
  int test = 3;
  int &testRef = test;

  // increments both!
  testRef++;

  cout << "test: " << test << ", testRef:" << testRef << "\n";

  /**
   * Doing a weird thing here, I realize:
   * tripleRef mutates the input...
   * but then I'm saving the output in a new var.
   * There's probably use cases for that, but it kind of defeats the purpose:
   * I'm BOTH mutating the input (saves memory) and allocating new memory for the result!
   * Probably want to choose one or the other deliberately.
  */
  cout << "running tripleRef on test...\n";
  int result = tripleRef(test);

  // I think this is more how you'd expect a mutating function to be used  
  int test2 = 5;
  tripleRef(test2);

  cout << "expecting all three variables to be 12\n";
  cout << "result var: " << result << "\n";
  cout << "test var: " << test << "\n";
  cout << "testRef var: " << testRef << "\n";

  // Now for a "pure" triple function
  int result2 = triplePure(test);

  cout << "Running non-mutating triplePure function...\n";
  cout << "expecting 36, 12, 12, and 15\n";
  cout << "result2 var: " << result2 << "\n";
  cout << "test var: " << test << "\n";
  cout << "testRef var: " << testRef << "\n";
  cout << "test2 var: " << test2 << "\n";

  // and finally we use a non-declarative ref to find memory locations.
  cout << "Expecting test and testRef to have the same location\n";
  cout << "Expecting result, result2, and test2 to be unique\n";
  printMemoryLocation(test, "test");
  printMemoryLocation(testRef, "testRef");
  printMemoryLocation(result, "result (mutated)");
  printMemoryLocation(result2, "result2 (nun-mutative)");
  printMemoryLocation(test2, "test2");

  // Okay wait what happens if we do this?
  //int &refOfFunctionCall = tripleRef(test2);
  //int &refOfPureFunctionCall = triplePure(test2);

  // Aha, we can't, at least not like that.
  // Both lines error out with the "must be an lvalue" message. 
  // (Good, I was worried that would be weird.)

  // And finally let's try a ref comparison
  if (&test == &testRef) {
    cout << "test and test2 have the same location\n";
  }
}