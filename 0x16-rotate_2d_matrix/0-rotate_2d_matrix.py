#!/usr/bin/python3

"""
Given an n x n 2D matrix, rotate it 90 degrees clockwise
"""


def rotate_2d_matrix(matrix):
    """
    Prototype: def rotate_2d_matrix(matrix)
    Do not return anything. The matrix must be edited in-place.
    You can assume the matrix will have 2 dimensions and will not be empty.
    """

    matrix_len = len(matrix[0])

    for i in range(matrix_len - 1, -1, -1):
        for j in range(0, matrix_len):
            matrix[j].append(matrix[i].pop(0))
