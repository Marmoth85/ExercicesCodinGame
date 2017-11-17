import sys
import math

lon = input()
lat = input()
n = int(input())

lon_rad, lat_rad = math.radians(float(".".join(lon.split(",")))), math.radians(float(".".join(lat.split(","))))

dist = 10 ** 10
name_defib = ""

for i in range(n):
    defib = input()
    defib_id, name, address, num, longit, latit = defib.split(";")
    longit_drad, latit_drad = math.radians(float(".".join(longit.split(",")))), math.radians(float(".".join(latit.split(","))))
    x = (longit_drad - lon_rad) * math.cos(.5 * (lat_rad + latit_drad))
    y = latit_drad - lat_rad
    d = 6371 * math.sqrt(x ** 2 + y ** 2)
    if d < dist:
        dist, name_defib = d, name
print(name_defib)