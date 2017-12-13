#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>

using namespace std;

struct MayanNumber {
	
	long _decimal_value = 0;
	int _length = 0;
	int _height = 0;
	map<string, int> _tab_values;
	vector<int> _mayan_base_values;
	vector<string> _mayan_value;
	
	MayanNumber(){}
	
	MayanNumber(const vector<string> & figures, int length, int height, const map<string, int> & tab_values) {
		_mayan_value = figures;
		_length = length;
		_height = height;
		_tab_values = tab_values;
		_mayan_base_values = readFigures(figures);
		_decimal_value = calculateMayanToDecimalValue(_mayan_base_values);
	}
	
	vector<int> readFigures(const vector<string> & figures) {
		int height = figures.size();
		int number_symbols = height / _height;
		vector<int> mayan_base_values;
		for(int i = 0; i < number_symbols; ++i) {
			string symbol = "";
			for(int j = 0; j < _height; ++j) {
				symbol += figures[i * _length + j];
			}
			mayan_base_values.push_back(_tab_values[symbol]);
		}
		return (mayan_base_values);
	}
	
	long calculateMayanToDecimalValue(const vector<int> & val) {
	    long decimal_value = 0;
	    int n = val.size();
	    for (int i = 0; i < n; ++i) {
	        decimal_value += (pow(20, n - 1 - i) * val[i]);
	    }
		return (decimal_value);
	}
	
	vector<int> calculateDecimalToMayanValue(long dec) {
		vector<int> mayan_result;
		stack<int> mayan_val;
		while (dec != 0) {
			mayan_val.push(dec % 20);
			dec /= 20;
		}
		while(!mayan_val.empty()) {
			mayan_result.push_back(mayan_val.top());
			mayan_val.pop();
		}
		if (mayan_result.size() == 0) mayan_result.push_back(0);
		return (mayan_result);
	}
	
	vector<string> buildMayanStringResult(const vector<int>& mayan_base) {
		vector<string> result;
		for(int i = 0; i < mayan_base.size(); ++i) {
			string symbol_line = findKeyFromValue(mayan_base[i]);
			for(int j = 0; j < _height; ++j) {
				result.push_back(symbol_line.substr(_length * j, _length));
			}
		}
		return (result);
	}
	
	string findKeyFromValue(int value) {
		map<string, int>::iterator it;
		string key = "none";
		for(it = _tab_values.begin(); it != _tab_values.end(); ++it) {
			if (it -> second == value) {
				key = it -> first;
				break;
			}
		}
		return (key);
	}
	
	void displayMayanValue() {
		for (int i = 0; i < _mayan_value.size(); ++i) {
			cout << _mayan_value[i] << endl;
		}
	}
	
	~MayanNumber(){}
};

MayanNumber operator+(const MayanNumber & val1, const MayanNumber & val2) {
	MayanNumber result;
	result._length = val1._length;
	result._height = val1._height;
	result._tab_values = val1._tab_values;
	result._decimal_value = val1._decimal_value + val2._decimal_value;
	result._mayan_base_values = result.calculateDecimalToMayanValue(result._decimal_value);
	result._mayan_value = result.buildMayanStringResult(result._mayan_base_values);
	return (result);
}

MayanNumber operator-(const MayanNumber & val1, const MayanNumber & val2) {
	MayanNumber result;
	result._length = val1._length;
	result._height = val1._height;
	result._tab_values = val1._tab_values;
	result._decimal_value = val1._decimal_value -	 val2._decimal_value;
	result._mayan_base_values = result.calculateDecimalToMayanValue(result._decimal_value);
	result._mayan_value = result.buildMayanStringResult(result._mayan_base_values);
	return (result);
}

MayanNumber operator*(const MayanNumber & val1, const MayanNumber & val2) {
	MayanNumber result;
	result._length = val1._length;
	result._height = val1._height;
	result._tab_values = val1._tab_values;
	result._decimal_value = val1._decimal_value * val2._decimal_value;
	result._mayan_base_values = result.calculateDecimalToMayanValue(result._decimal_value);
	result._mayan_value = result.buildMayanStringResult(result._mayan_base_values);
	return (result);
}

MayanNumber operator/(const MayanNumber & val1, const MayanNumber & val2) {
	MayanNumber result;
	result._length = val1._length;
	result._height = val1._height;
	result._tab_values = val1._tab_values;
	result._decimal_value = val1._decimal_value / val2._decimal_value;
	result._mayan_base_values = result.calculateDecimalToMayanValue(result._decimal_value);
	result._mayan_value = result.buildMayanStringResult(result._mayan_base_values);
	return (result);
}

int main()
{
    int L;
    int H;
    cin >> L >> H; cin.ignore();
	
	vector<string> mayan_figures(20, "");
	map<string, int> decimal_values; // will contain mayan figure in 1 line instead of vector<string> of H lines
	
    for (int i = 0; i < H; i++) {
        string numeral;
        cin >> numeral; cin.ignore();
		for (int j = 0; j < 20; ++j) {
			mayan_figures[j] += numeral.substr(L * j, L); // construct the 20 figures line after line
		}
    }
	
	for (int i = 0; i < 20; ++i) {
		decimal_values[mayan_figures[i]] = i; // store the "1 line mayan figure" in the map with decimal value association
	}
	
    int S1;
    cin >> S1; cin.ignore();
	vector<string> mayan_number1;
    for (int i = 0; i < S1; i++) {
        string num1Line;
        cin >> num1Line; cin.ignore();
		mayan_number1.push_back(num1Line);
    }
	
    int S2;
    cin >> S2; cin.ignore();
	vector<string> mayan_number2;
    for (int i = 0; i < S2; i++) {
        string num2Line;
        cin >> num2Line; cin.ignore();
		mayan_number2.push_back(num2Line);
    }
    
    string operation;
    cin >> operation; cin.ignore();
	MayanNumber mn1(mayan_number1, L, H, decimal_values);
	MayanNumber mn2(mayan_number2, L, H, decimal_values);
	MayanNumber result;
	if (operation == "+") result = mn1 + mn2;
	if (operation == "-") result = mn1 - mn2;
	if (operation == "*") result = mn1 * mn2;
	if (operation == "/") result = mn1 / mn2;
	result.displayMayanValue();
}