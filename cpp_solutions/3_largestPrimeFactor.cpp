#include <iostream>
#include <cassert>
#include <cmath>

/*
Problem 3: Largest prime factor
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the given number?
*/

long long largestPrimeFactor(long long num){
    long long largestFactor = -1;

    //remove all 2 that divide number
    while(num % 2 == 0){
        largestFactor = 2;
        num /= 2;
    }

    //num is odd, hence skip even nums
    for(long long i = 3; i<sqrt(num); i+=2){
        while(num % i == 0){
            largestFactor = i;
            num/= i;
        }
    }

    // handle case when num = 2
    if(num>2){
        largestFactor = num;
    }

    return largestFactor;

}

int main(){
    
    assert(largestPrimeFactor(2) == 2);
    assert(largestPrimeFactor(3) == 3);
    assert(largestPrimeFactor(5) == 5);
    assert(largestPrimeFactor(7) == 7);
    assert(largestPrimeFactor(8) == 2);
    assert(largestPrimeFactor(13195) == 29);
    assert(largestPrimeFactor(600851475143) == 6857);
    
    return 0;
}