#!/usr/bin/python3
"""
Validate if data is UTF-8
"""


def validUTF8(data):
    num = 0

    for i, n in enumerate(data):
        byte = n & 0xFF
        if num:
            if byte >> 6 != 2:
                return (False)
            num -= 1
            continue
        while (1 << abs(7 - num)) & byte:
            num += 1
        if num == 1 or num > 4:
            return (False)
        num = max(num - 1, 0)
    return (num == 0)
