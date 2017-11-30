#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
    
    vector<int> elevators(nbElevators);
    for (int i = 0; i < nbElevators; i++) {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        cin >> elevatorFloor >> elevatorPos; cin.ignore();
        elevators[elevatorFloor] = elevatorPos;
    }
    int latence = 0; // delay for blocking 0 for the first one, else one turn to have time to get the elevator
    while (1) {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();
        int target_position;
        if (exitFloor > cloneFloor) {
            target_position = elevators[cloneFloor];
        } else {
            target_position = exitPos;
        }
        int delta = 0;
        string action = "WAIT";
        if (direction == "RIGHT") {
            delta = 1;
        } else {
            delta = -1;
        }
        if (clonePos == 0 || clonePos == width - 1) {
            action = "BLOCK";
            latence = 1;
        }
        if (nbFloors > 1) {
            if ((target_position - clonePos) * delta < 0 && latence == 0) {
                action = "BLOCK";
                latence = 1;
            }
            if ((target_position - clonePos) * delta < 0 && latence != 0) {
                --latence;
            }
        }
        cout << action << endl;
    }
}