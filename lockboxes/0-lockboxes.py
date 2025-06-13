#!/usr/bin/python3
"""Define a function to see if all the boxes can be opened"""


def canUnlockAll(boxes):
    """function that checks if all the boxes can be opened"""
    opened = [0]
    new_key = True
    while new_key:
        new_key = False
        for box in boxes:
            if boxes.index(box) in opened:
                for i in box:
                    if i not in opened and i < len(boxes):
                        new_key = True
                        opened.append(i)
    if len(boxes) == len(opened):
        return True
    else:
        return False
