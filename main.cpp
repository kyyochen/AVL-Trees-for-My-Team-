#include <iostream>

#include <assert.h>

#include "roster_metrics.h"

void test() {
    roster_metrics roster = roster_metrics();
    roster.record(1, 1, 10);
    roster.record(1, 2, 5);
    roster.record(1, 3, 15);
    roster.record(2, 1, 10);
    roster.record(2, 2, 0);
    roster.record(2, 3, 30);

    assert(roster.ranked_receiver(1)==3);

    roster.clear(2,3);

    assert(roster.ranked_receiver(1)==1);

    std::cout << "Test succeeded!" << std::endl;
}

int main() {
    test();

    return 0;
}

//Questions:
/**
 * Can I add a search function in AVL_Tree'
 * How do I handle duplicate values in performance tree 
*/
