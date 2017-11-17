import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())  # the number of temperatures to analyse
t_res = 0 if n == 0 else 5526

for i in input().split():
    # t: a temperature expressed as an integer ranging from -273 to 5526
    t = int(i)
    if t == 0:
        break
    else:
        if abs(t) == abs(t_res):
            if t > t_res:
                t_res = t
        if abs(t) < abs(t_res):
            t_res = t
print(t_res)