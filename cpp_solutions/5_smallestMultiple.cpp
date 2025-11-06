#include <iostream>
#include <cassert>
#include <cmath>

/*
Problem 5: Smallest multiple
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to n?
*/

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

long long smallestMultiple(int n) {
    long long answer = 1;
    for (int i = 2;i <= n;i++) {
        answer = lcm(answer, i);
    }

    return answer;
}

int main() {

    assert(smallestMultiple(5) == 60);
    assert(smallestMultiple(7) == 420);
    assert(smallestMultiple(10) == 2520);
    assert(smallestMultiple(13) == 360360);
    assert(smallestMultiple(20) == 232792560);

    std::cout << "All Tests Passed" << std::endl;

    return 0;
}