#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string fromIntegerToBinaryString(int value, int size)
{
    string result = "";
    if (value > pow(2, size)) {
        cerr << "The value " << value << " is too big to be converted in only " << size << " bits" << endl;
        return "error";
    } else {
        for (int i = 0; i < size; ++i) {
            if (value % 2 == 0){
                result = "0" + result;
            } else {
                result = "1" + result;
            }
            value /= 2;
        }
        return result;
    }
}

int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);
    int string_size = MESSAGE.length();
    char letter;
    int ascii;
    string binary_message = "";
    string result = "";
    // Converts inputs of each ascii char in a string of 7 bits for each read ascii char
    for (int i = 0; i < string_size; ++i) {
        letter = MESSAGE[i];
        ascii = (int)(letter);
        binary_message += fromIntegerToBinaryString(ascii, 7);
    }
    // Read the binary string and convert it in unary string
    char current_char = binary_message[0];
    if (binary_message[0] == '0') {
        result += "00 0";
    } else {
        result += "0 0";
    }
    for (int i = 1; i < binary_message.length(); ++i) {
        if (binary_message[i] == current_char) {
            result += "0";
        } else {
            current_char = binary_message[i];
            if (current_char == '0') {
                result += " 00 0";
            } else {
                result += " 0 0";
            }
        }
    }
    cout << result << endl;
}