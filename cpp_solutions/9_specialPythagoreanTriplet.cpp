#include <iostream>
#include <cassert>

/*
Problem 9: Special Pythagorean triplet
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc such that a + b + c = n.
*/


long long specialPythagoreanTriplet(int n) {

    long long answer = 0;

    for (int a = 1; a < n; a++) {
        for (int b = a + 1; b < n;b++) {
            int c = n - a - b;
            if (a * a + b * b == c * c) {
                if (a + b + c == n) {
                    answer = a * b * c;
                }
            }
        }
    }

    return answer;
}



int main() {

    assert(specialPythagoreanTriplet(24) == 480);
    assert(specialPythagoreanTriplet(120) == 49920 || specialPythagoreanTriplet(120) == 55080 || specialPythagoreanTriplet(120) == 60000);
    assert(specialPythagoreanTriplet(1000) == 31875000);

    std::cout << "All Tests Passed" << std::endl;

    return 0;
}