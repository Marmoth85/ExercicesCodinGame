#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

int main()
{
    int W; // number of columns.
    int H; // number of rows.
    cin >> W >> H; cin.ignore();
    vector<vector<int>> grid;
    map<pair<int, string>, string> direction;
    direction[pair<int, string>(0, "TOP")] = "NONE";
    direction[pair<int, string>(0, "RIGHT")] = "NONE";
    direction[pair<int, string>(0, "LEFT")] = "NONE";
    direction[pair<int, string>(1, "TOP")] = "DOWN";
    direction[pair<int, string>(1, "RIGHT")] = "DOWN";
    direction[pair<int, string>(1, "LEFT")] = "DOWN";
    direction[pair<int, string>(2, "LEFT")] = "RIGHT";
    direction[pair<int, string>(2, "RIGHT")] = "LEFT";
    direction[pair<int, string>(3, "TOP")] = "DOWN";
    direction[pair<int, string>(4, "TOP")] = "LEFT";
    direction[pair<int, string>(4, "RIGHT")] = "DOWN";
    direction[pair<int, string>(5, "TOP")] = "RIGHT";
    direction[pair<int, string>(5, "LEFT")] = "DOWN";
    direction[pair<int, string>(6, "LEFT")] = "RIGHT";
    direction[pair<int, string>(6, "RIGHT")] = "LEFT";
    direction[pair<int, string>(7, "RIGHT")] = "DOWN";
    direction[pair<int, string>(7, "TOP")] = "DOWN";
    direction[pair<int, string>(8, "LEFT")] = "DOWN";
    direction[pair<int, string>(8, "RIGHT")] = "DOWN";
    direction[pair<int, string>(9, "LEFT")] = "DOWN";
    direction[pair<int, string>(9, "TOP")] = "DOWN";
    direction[pair<int, string>(10, "TOP")] = "LEFT";
    direction[pair<int, string>(11, "TOP")] = "RIGHT";
    direction[pair<int, string>(12, "RIGHT")] = "DOWN";
    direction[pair<int, string>(13, "LEFT")] = "DOWN";
    for (int i = 0; i < H; i++) {
        string LINE; // represents a line in the grid and contains W integers. Each integer represents one room of a given type.
        getline(cin, LINE);
        stringstream ss(LINE);
        string item = "";
        vector<int> toto;
        while (getline(ss, item, ' ')) toto.push_back(stoi(item));
        grid.push_back(toto);
    }
    int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> EX; cin.ignore();
    while (1) {
        int XI;
        int YI;
        string POS;
        cin >> XI >> YI >> POS; cin.ignore();
        int type_case = grid[YI][XI];
        string path = direction[pair<int, string>(type_case, POS)];
        if (path == "DOWN") ++YI;
        if (path == "RIGHT") ++XI;
        if (path == "LEFT") --XI;
        cout << to_string(XI) + " " + to_string(YI) << endl;
    }
}