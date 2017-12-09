#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore();
    vector<int> cotes(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v; cin.ignore();
        cotes.at(i) = v;
    }
    int answer = 0;
    int buy, sell, max_buy = 0;
    for(int i = 0; i < cotes.size(); ++i) {
        buy = cotes.at(i);
        sell = buy;
		if (max_buy < buy) {
			max_buy = buy;
			for (int j = i; j < cotes.size(); ++j) {
				if(sell > cotes.at(j)) {
					sell = cotes.at(j);
				}
			}
			if (sell - buy < answer) {
				answer = sell - buy;
			}
		}
    }
    cout << answer << endl;
}