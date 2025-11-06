"""
Problem 16: Power Digit Sum

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26
What is the sum of the digits of the number 2^1000?

"""

def sumDigits(number):
    return sum([int(digit) for digit in str(number)])
    
    

def powerdigitsum(number):
    power2 = 2**number
    answer = sumDigits(power2)
    return answer


def main():
    n = 1000
    output = powerdigitsum(n)
    print(output)   
    print("All Tests passed")


if __name__ == "__main__":
    main()
