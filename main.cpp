#include "foo.hpp"

#include <iostream>

auto main() -> int {
  foo::say_hello(std::cout, "dear cat");
}
