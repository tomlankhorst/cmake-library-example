#include "foo.hpp"

namespace foo {

void say_hello(std::ostream& out, std::string_view who) {
  out << "Hello, " << who;
}

}
