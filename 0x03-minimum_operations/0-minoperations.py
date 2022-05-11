#!/usr/bin/python3
"""
Minimum Operations
"""


def minOperations(n):
    """
    Function to calculate minimum operations
    to copy and paste elements to achieve
    len(n)
    """
    operations = 0

    if n <= 1:
        return 0

    if n == 2:
        return 2

    while (n > 1):
        for divisor in range(2, n + 1):
            if n % divisor == 0:
                operations += divisor
                n = n // divisor
                break
    return operations
