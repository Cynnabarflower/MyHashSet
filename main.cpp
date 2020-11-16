
#include <assert.h>
#include <iostream>
#include "HSet.h"

using namespace std;

int main() {
    auto set = HSet(4);

    set.put(Restaurant("a"));
    set.put(Restaurant("bb"));
    set.put(Restaurant("ccc"));
    set.put(Restaurant("dddd"));
    set.put(Restaurant("e"));
    set.put(Restaurant("ff"));
    set.put(Restaurant("gg"));

    assert(set.size() == 7);
    std::cout << set.toString() << std::endl;

    set.remove(Restaurant("bb"));
    assert(set.size() == 6);
    assert(set.contains(Restaurant("a")));
    assert(!set.contains(Restaurant("bb")));
    set.clear();
    assert(set.size() == 0);

}

