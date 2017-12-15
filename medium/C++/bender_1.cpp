#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int L;
    int C;
    cin >> L >> C; cin.ignore();
	
	vector<vector<char>> grid(L, vector<char>(C));
	bool breaker = false;
	map<string, int> orientation = {{"SOUTH", 1}, {"EAST", 2}, {"NORTH", 3}, {"WEST", 4}};
	map<char, string> action = {{'@', "START"}, {'$', "DIE"}, {'X', "OBSTACLE"}, {'#', "DEVIATE"}, {'S', "SOUTH"}, {'E', "EAST"}, {'N', "NORTH"}, {'W', "WEST"}, {'I', "INVERT"}, {'B', "BEER"}, {'T', "TRANSLATE"}, {' ', "WALK"}};
	
	int pos_i = 0, pos_j = 0;
	string direction = "SOUTH";
	int next_i = 0, next_j = 0;
	vector<string> moves;

    for (int i = 0; i < L; i++) {
        string row;
        getline(cin, row);
		for(int j = 0; j < C; ++j) {
			char cell = row[j];
			grid[i][j] = cell;
			if (cell = '@') {pos_i = i; pos_j= j;}
		}
    }
	
	int counter = 0;
	bool died = false;
	
	while(!died && counter < 1000000) {
		// check the next position depending on orientation
		if (orientation == "SOUTH") next_i = i+1;
		if (orientation == "NORTH") next_i = i-1;
		if (orientation == "WEST") next_j = j-1;
		if (orientation == "EAST3") next_j = j+1;
		char next_cell = grid[next_i][next_j];
		string act = action[next_cell];
		if (act == "OBSTACLE" && breaker) {
			grid[next_i][next_j] = ' ';
			act = "WALK";
		}
		if (act == "OBSTACLE" && !breaker) {
			act = "DEVIATE";
		}
		
	}
    cout << "answer" << endl;
	
}