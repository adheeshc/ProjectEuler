#include <iostream>
#include <cassert>
#include <cmath>

/*
Problem 4: Largest palindrome product
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two n-digit numbers.
*/

bool isPalindrome(int n) {
    std::string numStr = std::to_string(n);
    int i = 0;
    int j = numStr.size() - 1;

    while (i < j) {
        if (numStr[i] != numStr[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int largestPalindromeProduct(int n) {
    int answer = 1;

    long long upperBound = static_cast<long long>(std::pow(10, n) - 1);
    long long lowerBound = static_cast<long long>(std::pow(10, n-1));

    for (int i = upperBound; i > lowerBound; i--) {
        for (int j = upperBound; j > lowerBound; j--) {
            int product = i * j;
            if (isPalindrome(product)) {
                answer = std::max(product, answer);
            }
        }
    }

    return answer;
}



int main() {

    assert(largestPalindromeProduct(2) == 9009);
    assert(largestPalindromeProduct(3) == 906609);
    
    std::cout << "All Tests Passed" << std::endl;

    return 0;
}