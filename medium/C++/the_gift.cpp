#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N; cin.ignore();
    int C;
    cin >> C; cin.ignore();
    int total = 0;
    vector<int> budgets(N);
	map <int, int> distribution; // to store the typical budget and the number of people on that budget
	vector<int> prices(N);
    for (int i = 0; i < N; i++) {
        int B;
        cin >> B; cin.ignore();
        budgets[i] = B;
    }
    sort(budgets.begin(), budgets.end());
    for (vector<int>::iterator it = budgets.begin(); it != budgets.end(); ++it) {
		total += *it;
		map<int, int>::iterator itmap = distribution.find(*it);
		if (itmap != distribution.end()) ++itmap -> second;
		else distribution[*it] = 1;
	}
	if (total < C) cout << "IMPOSSIBLE" << endl;
	else {
	    int mean = C/N;
		int n_people = 0;
		for (int i = 0; i < budgets.size(); ++i) {
		    n_people = distribution[budgets[i]];
		    int test_price = budgets[i];
		    if (test_price > mean) test_price = mean;
		    C -= test_price;
		    if (i != N-1) mean = C / (N-i-1);
		    cout << test_price << endl;
		}
    }
}