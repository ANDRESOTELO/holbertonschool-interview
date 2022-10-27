#!/usr/bin/python3
"""Make changes script"""


def makeChange(coins, total):
    """Make changes function"""
    changes = 0
    sw = True

    if (total <= 0):
        return 0
    else:
        while sw is True:
            save = changes
            for coin in sorted(coins, reverse=True):
                if total >= coin:
                    if total % coin == 0:
                        changes = int(changes + total / coin)
                        sw = False
                        break
                    else:
                        changes = int(changes + total / coin)
                        total = total % coin
                        break
            if changes is save:
                return -1
    return int(changes)
