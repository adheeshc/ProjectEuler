#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

/*
Problem 14: Longest Collatz sequence
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)
Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under the given limit, produces the longest chain?

Note: Once the chain starts the terms are allowed to go above limit.

*/
unsigned long long getCollatz(unsigned long long n) {
    unsigned long long count = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            count++;
            
        }
        else {
            n = 3 * n + 1;
            count++;
        }
    }
    count++;
    return count;
}

int longestCollatzSequence(int n) {
    unsigned long long maxSequence = 0;
    int index = 0;
    for (unsigned long long i = 1; i < n; i++) {
        unsigned long long collatz = getCollatz(i);
        if (collatz > maxSequence) {
            maxSequence = collatz;
            index = i;
        }
    }
    return index;
}



int main() {

    assert(longestCollatzSequence(14) == 9);
    assert(longestCollatzSequence(5847) == 3711);
    assert(longestCollatzSequence(46500) == 35655);
    assert(longestCollatzSequence(54512) == 52527);
    assert(longestCollatzSequence(100000) == 77031);
    assert(longestCollatzSequence(1000000) == 837799);
    
    // std::cout << longestCollatzSequence(14) << std::endl;

    std::cout << "All Tests Passed" << std::endl;

    return 0;
}