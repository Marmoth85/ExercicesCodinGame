#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

    int deltaX = initialTX - lightX; // if > 0, have to go to West
    int deltaY = initialTY - lightY; // if > 0, have to go to North
    
    while (1) {
        int remainingTurns;
        cin >> remainingTurns; cin.ignore();
        string move = "";
        
        if (deltaY > 0) {
            move += "N";
            deltaY -= 1;
        } else if (deltaY < 0) {
            move += "S";
            deltaY += 1;
        }
        if (deltaX > 0) {
            move += "W";
            deltaX -= 1;
        } else if (deltaX < 0) {
            move += "E";
            deltaX += 1;
        }
        // A single line providing the move to be made: N NE E SE S SW W or NW
        cout << move << endl;
    }
}