#include <iostream>
#include <cassert>
#include <cmath>

/*
Problem 7: 10001st prime
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the nth prime number?
*/

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2;i * i <= n;i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int nthPrime(int n) {
    int answer = -1;
    int count = 0;
    for (int i = 1; i < INT32_MAX; i++) {
        if (isPrime(i)) {
            count++;
        }
        if (count == n) {
            return i;
        }
    }
    return answer;
}



int main() {

    assert(nthPrime(6) == 13);
    assert(nthPrime(10) == 29);
    assert(nthPrime(100) == 541);
    assert(nthPrime(1000) == 7919);
    assert(nthPrime(10001) == 104743);

    std::cout << "All Tests Passed" << std::endl;

    return 0;
}