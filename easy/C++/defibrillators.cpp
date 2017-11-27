#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    int N;
    cin >> N; cin.ignore();
    
    double lonA = 0, latA = 0, lonB = 0, latB = 0;
    lonA = stod(LON.replace(LON.find(","), 1, "."));
    latA = stod(LAT.replace(LAT.find(","), 1, "."));
    string name_result = "";
    double distance = pow(10, 10);
    double x, y, d;
    
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        vector<string> inputs;
        stringstream ss(DEFIB);
        string item = "";
        while (getline(ss, item, ';')) {
            inputs.push_back(item);
        }
        lonB = stod(inputs[4].replace(inputs[4].find(","), 1, "."));
        latB = stod(inputs[5].replace(inputs[5].find(","), 1, "."));
        
        x = (lonB - lonA) * cos ((latA + latB) / 2);
        y = (latB - latA);
        d = 6371 * sqrt(pow(x, 2) + pow(y, 2));
        
        if (d < distance) {
            distance = d;
            name_result = inputs[1];
        }
    }
    cout << name_result << endl;
}