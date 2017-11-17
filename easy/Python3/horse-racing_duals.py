import sys
import math

def index_for_value(liste, valeur):
    l = len(liste)
    if l == 0:
        return 0
    else:
        index_min, index_max, index_test = 0, l-1, int(.5 * (l - 1))
        found = False
        width = l
        counter = 0
        while not found and counter <= 100000:
            index_test = int((index_min + index_max) / 2)  
            if liste[index_test] >= valeur:
                index_max = index_test
            else:
                index_min = index_test
            width = index_max - index_min
            counter += 1
            if width <= 1:
                if valeur >= liste[index_min]:
                    index_test = index_max
                if valeur < liste[index_min]:
                    index_test = index_min
                if valeur >= liste[index_max]:
                    index_test = index_max + 1
                found = True
        return index_test
            
n = int(input())
ordered_list = []

for i in range(n):
    pi = int(input())
    index_insert = index_for_value(ordered_list, pi)
    ordered_list.insert(index_insert, pi)

d = 10 ** 10
for i in range(n):
    if i > 0:
        delta = ordered_list[i] - ordered_list[i-1]
        if delta < d:
            d = delta
print(d)