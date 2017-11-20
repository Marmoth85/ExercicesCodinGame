#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    while (1) {
        int max_height = -1;
        int mountain_index = -1;
        for (int i = 0; i < 8; i++) {
            int mountainH;
            cin >> mountainH; cin.ignore();
			if (mountainH > max_height) {
				max_height = mountainH;
				mountain_index = i;
			}
        }
        cout << mountain_index << endl;
    }
}