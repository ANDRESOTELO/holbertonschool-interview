#!/usr/bin/python3
'''
You have n number of locked boxes in front of you. 
Each box is numbered sequentially from 0 to n - 1 and 
each box may contain keys to the other boxes.
'''


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""

    total_boxes = len(boxes)
    lista_boxes = list(range(0, total_boxes))
    keys_list = boxes[0]
    
    if total_boxes <= 1:
        return True
    
    for key in keys_list:
        if key in lista_boxes:
            for key_box in boxes[key]:
                if key_box not in keys_list:
                    keys_list.append(key_box)
    
    keys_list.sort()

    if keys_list == lista_boxes:
        return True
    else:
        return False

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))

