#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long calculate_distance(const vector<long>& v, long val) {
    long d = 0;
    for (int i = 0; i < v.size(); ++i) d += abs(v[i] - val);
    return(d);
}

int main()
{
    int N;
    long min_x = pow(2,30), max_x = -min_x;
    cin >> N; cin.ignore();
    vector<long> y_house(N);
    for (int i = 0; i < N; i++) {
        int X;
        int Y;
        cin >> X >> Y; cin.ignore();
        y_house[i] = Y;
        if (X < min_x) min_x = X;
        if (X > max_x) max_x = X;
    }
    nth_element(y_house.begin(), y_house.begin() + y_house.size()/2, y_house.end());
    long med = y_house[N/2];
    long dy = calculate_distance(y_house, med);
    cout << (dy + max_x - min_x) << endl;
}