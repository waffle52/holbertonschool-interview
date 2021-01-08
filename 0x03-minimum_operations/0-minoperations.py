#!/usr/bin/python3
"""
This script calculates the fewest number of operations
needed to result in exactly n H characters in the file.
"""


def minOperations(n):
    if (n < 2):
        return (0)
    divide = 2
    sum = 0
    while divide <= n / 2:
        if (n % divide == 0):
            n //= divide
            sum += divide
        else:
            divide += 1
    return (sum + n)
