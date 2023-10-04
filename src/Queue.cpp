#include "Queue.h"
#include <iostream>

int main() {
  Queue<std::string> test(5);
  Queue<std::string>::setSentinel("ERROR");

  test.enqueue("one");
  test.enqueue("two");
  test.enqueue("three");
  test.enqueue("four");
  test.enqueue("five");
  test.dequeue();

  std::cout << "size(): " << test.size() << '\n';

  std::cout << "empty? " << test.empty() << '\n';
  //test.resize(6);

  std::cout << test.toString();

  test.enqueue("lol");

  return 0;
}