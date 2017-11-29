#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> searchNeighbor(vector<vector<int>> &grid, int x, int y, int inc_x, int inc_y) {
    vector<int> result;
    result.push_back(-1); 
    result.push_back(-1);
    int height = grid.size();
    int width = grid[0].size();
    bool found = false;
    bool limit = false;
    while (!found && !limit) {
        if (x + inc_x < width && y + inc_y < height) {
            x += inc_x;
            y += inc_y;
        } else {
            limit = true;
            break;
        }
        if (grid[y][x] == 1) {
            found = true;
            result[0] = x;
            result[1] = y;
            break;
        }
    }
    return result;
}

int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
	
	vector <vector<int>> grid(height, vector<int>(width));
	vector <vector<int>> nodes;
    for (int y = 0; y < height; y++) {
        string line;
        getline(cin, line);
        for (int x = 0; x < line.length(); ++x) {
            if (line[x] == '0') {
                grid[y][x] = 1;
                vector<int> coord(2);
                coord[0] = x; coord[1] = y;
                nodes.push_back(coord);
            }
        }
    }
    for (int i = 0; i < nodes.size(); ++i) {
        int x = nodes[i][0];
        int y = nodes[i][1];
        vector<int> right = searchNeighbor(grid, x, y, 1, 0);
        vector<int> bottom = searchNeighbor(grid, x, y, 0, 1);
        string result = to_string(x) + " " + to_string(y) + " " + to_string(right[0]) + " " + to_string(right[1]) + " " + to_string(bottom[0]) + " " + to_string(bottom[1]);
        cout << result << endl;
    }
}