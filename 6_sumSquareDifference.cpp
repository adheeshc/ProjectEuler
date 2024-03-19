#include <iostream>
#include <cassert>

/*

Problem 6: Sum square difference
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first n natural numbers and the square of the sum.

*/

long long sumOfSquares(int n) {
    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        answer += i * i;
    }

    return answer;
}

long long squareOfSum(int n) {
    long long answer = 0;

    for (int i = 1; i <= n;i++) {
        answer += i;
    }

    return answer * answer;
}

long long sumSquareDifference(int n) {
    return squareOfSum(n) - sumOfSquares(n);
}



int main() {

    assert(sumSquareDifference(10) == 2640);
    assert(sumSquareDifference(20) == 41230);
    assert(sumSquareDifference(100) == 25164150);

    std::cout << "All Tests Passed" << std::endl;

    return 0;
}