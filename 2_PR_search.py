import numpy as np
from random import random
import time

def internal_test(items):
    start_time = time.time()
    items.sort()
    return (time.time() - start_time)

def counter_sort(items):
    min_number = min(items)
    max_number = max(items)
    n = max_number - min_number + 1 
    counters = [0] * n

    for v in items:
        counters[v - min_number] += 1

    result = []
    for v, count in enumerate(counters):
        result.extend([v + min_number] * count)
        
    return result

def counter_test(items):
    start_time = time.time()
    counter_sort(items)
    return (time.time() - start_time)


repeats = 101
itemsfind = 60
maxpower = 7
for j in range (1,maxpower):
    inter = 0
    counter = 0
    h = 10**j
    for i in range (1,repeats):
        a = np.random.randint(0, 100, h).tolist()
        b = a.copy()
        inter = inter + internal_test(a)
        counter = counter + counter_test(b)
    print("Time for", repeats-1, "repeats of internal sort of",itemsfind,"elements in",h,"=","{:e}".format(inter/(repeats-1)))
    print("Time for", repeats-1, "repeats of counter sort of",itemsfind,"elements in",h,"=","{:e}".format(counter/(repeats-1)))
    print()
input()