#!/usr/bin/python3
"""Calculate Pascal Triangle"""


def pascal_triangle(n):
    """
    Function for creating a pascal triangle
    n: number of rows
    Return: An empty list if n <= 0
    """
    if n <= 0:
        return ([])

    pascal = [[1]]
    for i in range(1, n):
        row = [1]
        prev = pascal[i - 1]
        for j in range(len(prev)):
            new = prev[j] + prev[j + 1] if j != len(prev) - 1 else 1
            row.append(new)

        pascal.append(row)

    return pascal
