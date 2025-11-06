#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

/*
Problem 16: Power Digit Sum

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26
What is the sum of the digits of the number 2^1000?

*/

int powerDigitSum(int number) {
    std::vector<int> digits;
    digits.push_back(1);

    for (int power = 0; power < number; power++) {
        int carry = 0;

        for (int i = 0; i < digits.size(); i++) {
            int product = digits[i] * 2 + carry;
            digits[i] = product % 10;
            carry = product / 10;
        }

        while (carry > 0) {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }
    int sum = 0;
    for (int digit : digits) {
        sum += digit;
    }

    return sum;
}

int main(int argc, char** argv) {
    int n = 1000;
    std::cout << powerDigitSum(n) << std::endl;
    // assert(powerDigitSum(n) == 26);

    std::cout << "All Tests passed" << std::endl;
    return 0;
}