#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int calculate_distance(const vector<int>& v, int val) {
    int d = 0;
    for (int i = 0; i < v.size(); ++i) d += abs(v[i] - val);
    return(d);
}

int main()
{
    int N, min_x = pow(2,30), max_x = -min_x, min_y = min_x, max_y = max_x;
    cin >> N; cin.ignore();
    vector<int> y_house(N);
    for (int i = 0; i < N; i++) {
        int X;
        int Y;
        cin >> X >> Y; cin.ignore();
        y_house[i] = Y;
        if (Y < min_y) min_y = Y;
        if (Y > max_y) max_y = Y;
        if (X < min_x) min_x = X;
        if (X > max_x) max_x = X;
        //cerr << X << "    " << Y << endl;
    }
    //cerr << "Min(Xi) = " << min_x << "    Max(Xi) = " << max_x << endl;
    //cerr << "Min(Yi) = " << min_y << "    Max(Yi) = " << max_y << endl;
    int dy = pow(2, 30);
    for (int yi = min_y; yi <= max_y; ++yi) {
        int d = calculate_distance(y_house, yi);
        if (d < dy) dy = d;
    }
    cout << (dy + max_x - min_x) << endl;
}