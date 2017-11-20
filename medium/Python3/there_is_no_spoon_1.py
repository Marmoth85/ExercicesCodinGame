import sys
import math

width = int(input())  # the number of cells on the X axis
height = int(input())  # the number of cells on the Y axis

def search_neighbor_right(grid, node):
    x, y = node
    xn, yn = -1, -1
    length = len(grid[y][:])
    if length <= 1:
        return [xn, yn]
    else:
        index, found = 1, False
        while (x + index) < length and not found:
            value = grid[y][x + index]
            if value == 1:
                xn, yn = x + index, y
                found = True
            index += 1
        return [xn, yn]


def search_neighbor_bottom(grid, node):
    x, y = node
    xn, yn = -1, -1
    length = len(grid)
    if length <= 1:
        return [xn, yn]
    else:
        index, found = 1, False
        while (y + index) < length and not found:
            value = grid[y + index][x]
            if value == 1:
                xn, yn = x, y + index
                found = True
            index += 1
        return [xn, yn]


grid = [[0] * width for i in range(height)]
node_list = []

# Filling the 2D list and the node list
for i in range(height):
    line = input()  # width characters, each either 0 or .
    for j in range(width):
        if line[j] == "0":
            grid[i][j] = 1
            node_list.append([j, i])
# Iterating on node_list in order to find the neighbors for each node
for node in range(len(node_list)):
    x, y = node_list[node]
    x_vd, y_vd = search_neighbor_right(grid, [x, y])
    x_vb, y_vb = search_neighbor_bottom(grid, [x, y])
    node_neighborhood = " ".join([str(x), str(y), str(x_vd), str(y_vd), str(x_vb), str(y_vb)])
    print(node_neighborhood)