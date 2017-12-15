#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

vector<int> findPosition(int next_i, int next_j, const vector<vector<char>> & grid, const char & caracter) {
    vector<int> result;
    bool found = false;
    for (int i = 0; i < grid.size() && !found; ++i) {
        for (int j = 0; j < grid[0].size() && !found; ++j) {
            if (grid[i][j] == caracter) {
                if (next_i != i || next_j != j) {
                    found = true;
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
    }
    return (result);
}

int main()
{
    int L;
    int C;
    cin >> L >> C; cin.ignore();
	
	vector<vector<char>> grid(L, vector<char>(C));
	bool breaker = false;
	map<string, int> orientation = {{"SOUTH", 1}, {"EAST", 2}, {"NORTH", 3}, {"WEST", 4}};
	map<char, string> action = {{'@', "START"}, {'$', "DIE"}, {'X', "OBSTACLE"}, {'#', "DEVIATE"}, {'S', "SOUTH"}, {'E', "EAST"}, {'N', "NORTH"}, {'W', "WEST"}, {'I', "INVERT"}, {'B', "BEER"}, {'T', "TRANSLATE"}, {' ', "WALK"}};
	
	vector<int> posBender(2);
	vector<int> nextPosBender(2);
	string direction = "SOUTH";
	string next_direction = "SOUTH";
	vector<string> moves;

    for (int i = 0; i < L; i++) {
        string row;
        getline(cin, row);
		for(int j = 0; j < C; ++j) {
			char cell = row[j];
			grid[i][j] = cell;
		}
    }
	
	int counter = 0;
	bool died = false;
	int test_direction = 1;
	posBender = findPosition(-1, -1, grid, '@');
	
	while(!died && counter < 10000) {
	    nextPosBender[0] = posBender[0];
	    nextPosBender[1] = posBender[1];
		if (direction == "SOUTH") nextPosBender[0] = posBender[0] + 1;
		if (direction == "NORTH") nextPosBender[0] = posBender[0] - 1;
		if (direction == "WEST") nextPosBender[1] = posBender[1] - 1;
		if (direction == "EAST") nextPosBender[1] = posBender[1] + 1;
		char next_cell = grid[nextPosBender[0]][nextPosBender[1]];
		string act = action[next_cell];
		if (act == "OBSTACLE" && breaker) {
			grid[nextPosBender[0]][nextPosBender[1]] = ' ';
			act = "WALK";
		}
		if (act == "OBSTACLE" && !breaker) {
			act = "DEVIATE";
		}
		if (act == "BEER") {
		    breaker = !breaker;
		    act = "WALK";
		}
		if (act == "TRANSLATE") {
		    vector<int> temp;
		    temp = findPosition(nextPosBender[0], nextPosBender[1], grid, 'T');
		    nextPosBender = temp;
		    act = "WALK";
		}
		if (act == "START") act == "WALK";
		if (act == "INVERT") {
		    map<string, int>::iterator it = orientation.begin();
		    while (it != orientation.end()) {
		        it -> second = 5 - it -> second; // 1->4, 2->3, 3->2, 4->1.
		        ++it;
		    }
		    act = "WALK";
		}
		if (act == "SOUTH") {
		    next_direction = "SOUTH";
		    act = "WALK";
		}
		if (act == "EAST") {
		    next_direction = "EAST";
		    act = "WALK";
		}
		if (act == "NORTH") {
		    next_direction = "NORTH";
		    act = "WALK";
		}
		if (act == "WEST") {
		    next_direction = "WEST";
		    act = "WALK";
		}
		if (act == "DEVIATE") {
		    map<string, int>::iterator it;
		    for (it = orientation.begin(); it != orientation.end(); ++it) {
		        if (it -> second == test_direction) direction = it -> first;
		    }
		    ++test_direction;
		    if (test_direction > 4) test_direction = 1;
		    next_direction = direction;
		    continue;
		}
		if (act == "DIE") {
		    died = true;
		    act = "WALK";
		}
		if (act == "WALK") {
		    posBender[0] = nextPosBender[0];
		    posBender[1] = nextPosBender[1];
		    moves.push_back(direction);
		    direction = next_direction;
		    test_direction = 1;
		    ++counter;
		}
	}
	if (counter == 10000) cout << "LOOP" << endl;
	else {
	    for (int i = 0; i < moves.size(); ++i) {
	        cout << moves[i] << endl;
	    }
	}
	
}