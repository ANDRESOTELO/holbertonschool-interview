#!/usr/bin/python3
"""
UTF-8 Validation
"""


def validUTF8(data):
    """
    Method that determines if data set represents a valid
    UTF-8 encoding
    """

    # Number of bytes in UTF-8 Character
    number_bytes = 0
    mask1 = 1 << 7
    mask2 = 1 << 6

    for i in data:

        n_byte = 1 << 7

        if number_bytes == 0:
            while n_byte & i:
                number_bytes += 1
                n_byte = n_byte >> 1
            if number_bytes == 0:
                continue
            if number_bytes == 1 or number_bytes > 4:
                return False

        else:
            if not (i & mask1 and not (i & mask2)):
                return False
        number_bytes -= 1

    # All characters were verified
    if number_bytes == 0:
        return True

    return False