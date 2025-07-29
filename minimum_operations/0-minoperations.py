#!/usr/bin/python3
"""Module to determine the minimum number of operations
to reach a given number of characters in a text file.
"""


def minOperations(n):
    """Determine the minimum number of operations to reach n characters."""

    if n <= 1:
        return 0

    min_operations = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            min_operations += factor
            n //= factor
        factor += 1

    return min_operations
