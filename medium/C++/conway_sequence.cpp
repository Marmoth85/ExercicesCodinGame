#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> splitStringToInt(const string& str, const char& delim)
{
    vector<int> result;
    stringstream ss(str);
    string item = "";
    while (getline(ss, item, delim))
    {
        result.push_back(stoi(item));
    }
    return result;
}

int main()
{
    int R;
    cin >> R; cin.ignore();
    int L;
    cin >> L; cin.ignore();
	
	string answer = to_string(R);
	
	for (int i = 2; i <= L; ++i) {
		vector<int> vec_sequence = splitStringToInt(answer, ' ');
		answer = "";
		int number = vec_sequence[0];
		int count = 0;
		for(int j = 0; j < vec_sequence.size(); ++j) {
		    int current_value = vec_sequence[j];
			if (number == current_value) {
				++count;
			} else {
			    answer = answer + to_string(count) + " " + to_string(number) + " ";
				number = current_value;
				count = 1;
			}
			if (j == vec_sequence.size() - 1) {
			    answer = answer + to_string(count) + " " + to_string(number);
			}
		}
	}	
    cout << answer << endl;
}