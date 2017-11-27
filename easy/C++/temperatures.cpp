#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
	int result;
	if (n == 0) {
		result = 0;
	} else {
		result = 5526;
	}
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
		if (abs(t) < abs(result) || abs(t) == abs(result) && t > result) {
			result = t;
		}	
    }
    cout << result << endl;
}