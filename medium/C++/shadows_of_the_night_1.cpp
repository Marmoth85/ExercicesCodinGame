#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int calculate(int val_min, int val_max, int current_val) {
    int new_val = (val_min + val_max) / 2;
    if (new_val == current_val) {
        if (val_min == current_val) {
            return(val_max);
        } else {
            return(val_min);
        }
    }
    else {
        return(new_val);
    }
}


int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();
    int Xmin_strict = 0, Xmax_strict = W;
    int Ymin_strict = 0, Ymax_strict = H;
    int Xnew = X0;
    int Ynew = Y0;

    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();
        cerr << "Détecteur : " << bombDir << endl;
        if (bombDir.find('U') != string::npos) {
            cerr << "La bombe est au dessus" << endl;
            Ymax_strict = Y0;
            Ynew = calculate(Ymin_strict, Ymax_strict, Y0);
        }
        if (bombDir.find('D') != string::npos) {
            cerr << "La bombe est en dessous" << endl;
            Ymin_strict = Y0;
            Ynew = calculate(Ymin_strict, Ymax_strict, Y0);
        }
        if (bombDir.find('R') != string::npos) {
            cerr << "La bombe est sur la droite" << endl;
            Xmin_strict = X0;
            Xnew = calculate(Xmin_strict, Xmax_strict, X0);
        }
        if (bombDir.find('L') != string::npos) {
            cerr << "La bombe est sur la gauche" << endl;
            Xmax_strict = X0;
            Xnew = calculate(Xmin_strict, Xmax_strict, X0);
        }
        cout << to_string(Xnew) << " " << to_string(Ynew) << endl;
        X0 = Xnew;
        Y0 = Ynew;
    }
}