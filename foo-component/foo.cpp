/**
 * This source-file is only required to build the library. 
 * It does not need to be shipped with the built library.
 */

#include "foo.hpp"

namespace foo {

void say_hello(std::ostream& out, std::string_view who) {
  out << "Hello, " << who;
}

}
