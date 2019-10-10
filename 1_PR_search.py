import numpy as np
from random import random
import time

def linear_search(items, items_to_find):
    count = 0
    for item_to_find in items_to_find:
        if item_to_find in items:
            count += 1
    return count

def binary_search(items, items_to_find):
    N = len(items)
    items.sort()
    count = 0
    for item_to_find in items_to_find:
        number = item_to_find
        low = 0
        high = N-1
        while low <= high:
            mid = (low + high) // 2
            if number < items[mid]:
                high = mid - 1
            elif number > items[mid]:
                low = mid + 1
            else:
                count += 1
                break
    return count

def duplicate_search(items):
    N = len(items)
    for i in range (0, N-1):
        for j in range (i+1, N):
            if items[i]==items[j]:
                return False
    return True

def linear_test(a,b):
    start_time = time.time()
    linear_search(a,b)
    return (time.time() - start_time)

def binary_test(a,b):
    start_time = time.time()
    binary_search(a,b)
    return (time.time() - start_time)

def duplicate_test(a):
    start_time = time.time()
    duplicate_search(a)
    return (time.time() - start_time)


repeats = 101
itemsfind = 60
maxpower = 6
for j in range (1,maxpower):
    l = 0
    bi = 0
    d = 0
    dd = 0
    for i in range (1,repeats):
        h = 10**j
        a = np.random.randint(0, 10000000, h).tolist()
        b = np.random.randint(0, 10000000, itemsfind).tolist()
        c = []
        for m in range (0,itemsfind):
            c.append(m*2**m)
        l = l + linear_test(a,b)
        d = d + duplicate_test(b)
        bi = bi + binary_test(a,b)
        dd = dd + duplicate_test(c)
    print("Time for", repeats-1, "repeats of linear search of",itemsfind,"elements in",h,"=","{:e}".format(l/(repeats-1)))
    print("Time for", repeats-1, "repeats of binary search of",itemsfind,"elements in",h,"=","{:e}".format(bi/(repeats-1)))
    print("Time for", repeats-1, "repeats of duplicate search in",itemsfind,"=","{:e}".format(d/(repeats-1)))
    print("Time for", repeats-1, "repeats of duplicate different search in",itemsfind,"=","{:e}".format(dd/(repeats-1)))
    print()
