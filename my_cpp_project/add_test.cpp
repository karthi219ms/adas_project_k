// add_test.cc
#include "add.h"
#include <cassert>

int main() {
    assert(add(2, 3) == 5);
    assert(add(-1, 1) == 0);
    return 0;
}
