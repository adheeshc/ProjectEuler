#include <iostream>
#include <unordered_set>
#include <cassert>

/*
Problem 1: Multiples of 3 or 5
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below the provided parameter value number.
*/

int multiplesOf3Or5(int number){
    std::unordered_set<int> s1;

    for(int i = 1; i<number; i++){
        if(3*i < number)
            s1.insert(3*i);
        if(5*i < number)
            s1.insert(5*i);
    }

    int sumOfElements = 0;
    for(int i:s1){
        sumOfElements += i;
    }
    return sumOfElements;
}

int main(int argc, char **argv){
    
    assert(multiplesOf3Or5(10) == 23);
    assert(multiplesOf3Or5(49) == 543);
    assert(multiplesOf3Or5(1000) == 233168);
    assert(multiplesOf3Or5(8456) == 16687353);
    assert(multiplesOf3Or5(19564) == 89301183);

    std::cout<< "All Tests Passed" << std::endl;
    return 0;
}