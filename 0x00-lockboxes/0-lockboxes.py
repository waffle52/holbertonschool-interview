#!/usr/bin/python3
"""
Determines if all the locked boxes can be opened
from gathering keys from other boxes
"""


def connect(T, R):
    res = []
    for x in R:
        res += T[x]
    return res


def canUnlockAll(boxes):
    index = 0
    total = list(set(boxes[0]) | {0})
    added = True
    while added:
        added = False
        for i in connect(boxes, total[index:]):
            if i not in total:
                total.append(i)
                index += 1
                added = True
    return (len(total) == len(boxes))
