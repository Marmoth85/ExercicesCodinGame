import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

l = int(input())
h = int(input())
t = input() # String à mettre en ascii

a_min, a_maj, z_min, z_maj = ord("a"), ord("A"), ord("z"), ord("Z")

for i in range(h):
    row = input() # Contient les lignes des 27 caractères ascii
    
    string_res = ""
    # On cherche l'indice de la lettre à printer dans le tableau
    for char in t:
        index_char = ord(char)
        letter_index = 26
        if index_char >= a_min and index_char <= z_min:
            letter_index = index_char - a_min
        if index_char >= a_maj and index_char <= z_maj:
            letter_index = index_char - a_maj
        string_res += row[l * letter_index : l * (letter_index + 1)]
    print(string_res)