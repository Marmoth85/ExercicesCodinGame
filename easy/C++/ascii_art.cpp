#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    for (int i = 0; i < H; i++) {
        string ROW;
        string result = "";
        getline(cin, ROW);
        for(int j = 0; j < T.length(); ++j) {
            int ascii = (int)(T[j]);
            int letter_index;
            if (ascii >= 97 && ascii <= 122) {
                ascii -= 32;
            }        
            if (ascii < 65 || ascii > 90) {
                letter_index = 26;
            } else {
                letter_index = ascii - 65;
            }
            result += ROW.substr(L * letter_index, L);
            }
        cout << result << endl;
    }
}