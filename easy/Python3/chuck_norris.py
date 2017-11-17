import sys
import math

message = input() # ascii 7 bits
bin_message = ""

# conversion du message en binaire (stocké en str)
for letter in message:
    bin_value = bin(ord(letter))
    bin_char = str(bin_value).split("0b")[1]
    while len(bin_char) < 7:
        bin_char = str("0") + bin_char
    bin_message += bin_char

# lire le binaire de bits en bits et regrouper en blocs
result = ""
current_bit = bin_message[0]
if current_bit == "0":
    result += "00 "
else:
    result += "0 "

for b in bin_message:
    if b == current_bit:
        result += "0"
    else:
        current_bit = b
        if b == "0":
            result += " 00 0"
        else:
            result += " 0 0"

print(result)