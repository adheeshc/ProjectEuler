#include <iostream>
#include <cassert>
#include <vector>

/*
Problem 10: Summation of primes
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below n.
*/

bool isPrime(long long n) {
    if (n <= 1) {
        return false;
    }
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

long long primeSummation(long long n) {
    long long answer = 0;
    for (long long i = 0;i < n;i++) {
        if (isPrime(i)) {
            answer += i;
        }
    }
    return answer;
}



int main() {
    assert(primeSummation(10) == 17);
    assert(primeSummation(17) == 41);
    assert(primeSummation(2001) == 277050);
    assert(primeSummation(140759) == 873608362);
    assert(primeSummation(2000000) == 142913828922);

    std::cout << primeSummation(2000000) << std::endl;

    std::cout << "All Tests Passed" << std::endl;

    return 0;
}