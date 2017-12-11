#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int calculate_score(const string& word, map<char, int>& table_points) {
    int result = 0;
    for (int i = 0; i < word.length(); ++i) {
        result += table_points[word[i]];
    }
    return(result);
}

map<char, int> compute_map_caracters(const string& str) {
	map<char, int> enumerate_caracters;
	for(int i = 0; i < str.length(); ++i) {
		map<char, int>::iterator iter = enumerate_caracters.find(str[i]);
		if (iter != enumerate_caracters.end()) ++(enumerate_caracters[str[i]]);
		else enumerate_caracters[str[i]] = 1;
	}
	return(enumerate_caracters);
}

bool check_letters(const string& word, const string& letters) {
    bool ok = true;
	map<char, int> char_word = compute_map_caracters(word);
	map<char, int> char_letter = compute_map_caracters(letters);
	for(map<char, int>::iterator iter = char_word.begin(); iter != char_word.end(); ++iter) {
		if (iter -> second > char_letter[iter -> first]) {
			ok = false;
			break;
		}
	}
    return (ok);
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    vector<pair<string, int>> dict;
    map<char, int> pts;
    pts['e'] = pts['a'] = pts['i'] = pts['o'] = pts['n'] = pts['r'] = pts['t'] =  pts['l'] = pts['s'] = pts['u'] = 1;
    pts['d'] = pts['g'] = 2;
    pts['b'] = pts['c'] = pts['m'] = pts['p'] = 3;
    pts['f'] = pts['h'] = pts['v'] = pts['w'] = pts['y'] = 4;
    pts['k'] = 5;
    pts['j'] = pts['x'] = 8;
    pts['q'] = pts['z'] = 10;
    for (int i = 0; i < N; i++) {
        string W;
        getline(cin, W);
        dict.push_back(make_pair(W, calculate_score(W, pts)));
    }
    string LETTERS;
    getline(cin, LETTERS);
    int max_possible_score = calculate_score(LETTERS, pts);
    string best_word;
    bool found = false;
    for(int i = max_possible_score; i > 0; --i) {
        for(int j = 0; j < dict.size(); ++j) {
            if ((dict[j]).second == i) {
                string test = dict[j].first;
                if (check_letters(test, LETTERS)) {
                    best_word = test;
                    found = true;
                }
            }
            if (found) break;
        }
        if (found) break;
    }
    cout << best_word << endl;
}