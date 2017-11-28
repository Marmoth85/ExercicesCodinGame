#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N; cin.ignore();
    vector<int> horses_power(N);
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        horses_power[i] = Pi;
    }
    sort(horses_power.begin(), horses_power.end());
    int answer  = 10000001;
    int temp_value;
    for (int i = 1; i < N; ++i) {
        temp_value = horses_power[i] - horses_power[i - 1];
        if (temp_value < answer) {
            answer = temp_value;
        }
    }
    cout << answer << endl;
}