import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
# ---
# Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.

# light_x: the X position of the light of power
# light_y: the Y position of the light of power
# initial_tx: Thor's starting X position
# initial_ty: Thor's starting Y position
light_x, light_y, initial_tx, initial_ty = [int(i) for i in input().split()]

position_tx = initial_tx
position_ty = initial_ty
# game loop
while True:
    remaining_turns = int(input())  # The remaining amount of turns Thor can move. Do not remove this line.

    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr)
    
    move = ""

    if position_ty < light_y:
        position_ty += 1
        move += "S"
    elif position_ty > light_y:
        position_ty -= 1
        move += "N"
    if position_tx < light_x:
        position_tx += 1
        move += "E"
    elif position_tx > light_x:
        position_tx -= 1
        move += "W"

    # A single line providing the move to be made: N NE E SE S SW W or NW
    print(move)