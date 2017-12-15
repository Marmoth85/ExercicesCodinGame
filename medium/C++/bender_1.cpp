#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

vector<int> findPosition(int next_i, int next_j, const vector<vector<char>> & grid, const char & caracter) {
    vector<int> result;
    bool found = false;
    cerr << "Forbidden coords : " << next_i << "    " << next_j << endl;
    cerr << "Char searched : " << caracter << endl;
    cerr << "grid.size() = " << grid.size() << endl;
    for (int i = 0; i < grid.size() && !found; ++i) {
        cerr << "grid[0].size() = " << grid[0].size() << endl;
        for (int j = 0; j < grid[0].size() && !found; ++j) {
            cerr << grid[i][j];
            if (grid[i][j] == caracter) cerr << endl << "trouvé en " << i << ", " << j << endl;
            if (grid[i][j] == caracter) {
                if (next_i != i || next_j != j) {
                    found = true;
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        cerr << endl;
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

    cerr << "La grille est la suivante : " << endl;
    for (int i = 0; i < L; i++) {
        string row;
        getline(cin, row);
		for(int j = 0; j < C; ++j) {
			char cell = row[j];
			grid[i][j] = cell;
		}
		cerr << row << endl;
    }
	
	int counter = 0;
	bool died = false;
	int test_direction = 1;
	posBender = findPosition(-1, -1, grid, '@');
	
	cerr << "On entre dans le while" << endl;
	while(!died && counter < 10000) {
	    nextPosBender[0] = posBender[0];
	    nextPosBender[1] = posBender[1];
	    cerr << "Bender est en (x, y) = (" << posBender[0] << ", " << posBender[1] << ")" << endl;
	    cerr << "Direction : " << direction << endl;
	    cerr << "Next direction : " << next_direction << endl;
		if (next_direction == "SOUTH") nextPosBender[0] = posBender[0] + 1;
		if (next_direction == "NORTH") nextPosBender[0] = posBender[0] - 1;
		if (next_direction == "WEST") nextPosBender[1] = posBender[1] - 1;
		if (next_direction == "EAST") nextPosBender[1] = posBender[1] + 1;
		cerr << "Les coordonnées suivantes sont : (" << nextPosBender[0] << ", " << nextPosBender[1] << ")" << endl;
		char next_cell = grid[nextPosBender[0]][nextPosBender[1]];
		string act = action[next_cell];
		cerr << "Action is " << act << endl;
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
		    cerr << "truc" << endl;
		    cerr << nextPosBender.size() << endl;
		    cerr << temp.size() << endl;
		    nextPosBender = temp;
		    cerr << nextPosBender.size() << endl;
		    cerr << "Les coordonnées suivantes sont : (" << nextPosBender[0] << ", " << nextPosBender[1] << ")" << endl;
		    act = "WALK";
		}
		if (act == "START") act == "WALK";
		if (act == "INVERT") {
		    map<string, int>::iterator it = orientation.begin();
		    while (it != orientation.end()) {
		        cerr << "Priority is : " << it -> second << endl;
		        it -> second = 5 - it -> second; // 1->4, 2->3, 3->2, 4->1.
		        cerr << "Prioriry now is : " << it -> second << endl;
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
		        if (it -> second == test_direction) next_direction = it -> first;
		    }
		    ++test_direction;
		    if (test_direction > 4) test_direction = 1;
		    continue;
		}
		if (act == "DIE") {
		    died = true;
		    act = "WALK";
		}
		if (act == "WALK") {
		    posBender[0] = nextPosBender[0];
		    posBender[1] = nextPosBender[1];
		    direction = next_direction;
		    moves.push_back(direction);
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