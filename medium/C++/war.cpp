#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int main()
{
	map<string,int> cards_value;
	cards_value["2"] = 2;
	cards_value["3"] = 3; 
	cards_value["4"] = 4;
	cards_value["5"] = 5;
	cards_value["6"] = 6;
	cards_value["7"] = 7;
	cards_value["8"] = 8;
	cards_value["9"] = 9;
	cards_value["10"] = 10;
	cards_value["J"] = 11;
	cards_value["Q"] = 12;
	cards_value["K"] = 13;
	cards_value["A"] = 14;
	
	queue<string> player1, player2;
	
    int n; // the number of cards for player 1
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string cardp1; // the n cards of player 1
        cin >> cardp1; cin.ignore();
		player1.push(cardp1);
    }
    int m; // the number of cards for player 2
    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++) {
        string cardp2; // the m cards of player 2
        cin >> cardp2; cin.ignore();
		player2.push(cardp2);
    }
	
	int number_games = 0;
	string winner = "";
	queue<string> temp1, temp2;
	while(1) {
		if (!player1.empty() && !player2.empty()) {
			temp1.push(player1.front());
			player1.pop();
			temp2.push(player2.front());
			player2.pop();
			string cardp1 = temp1.back();
			string cardp2 = temp2.back();
			int p1 = cards_value[cardp1.substr(0, cardp1.length()-1)];
			int p2 = cards_value[cardp2.substr(0, cardp2.length()-1)];
			if (p1 > p2) {
				for(int i = 0; !temp1.empty(); ++i) {
					player1.push(temp1.front());
					temp1.pop();
				}
				for(int i = 0; !temp2.empty(); ++i) {
					player1.push(temp2.front());
					temp2.pop();
				}
				++number_games;
			}
			if (p1 < p2) {
				for(int i = 0; !temp1.empty(); ++i) {
					player2.push(temp1.front());
					temp1.pop();
				}
				for(int i = 0; !temp2.empty(); ++i) {
					player2.push(temp2.front());
					temp2.pop();
				}
				++number_games;
			}
			if (p1 == p2) {
			    if (player1.size() >= 3 && player2.size() >= 3) {
    				for (int i = 0; i < 3; ++i) {
    					temp1.push(player1.front());
    					temp2.push(player2.front());
    					player1.pop();
    					player2.pop();
    				}
			    } else {
			        winner = "PAT";
			        break;
			    }
			}
		} else {
			if (player1.empty()) {
				winner = "2 ";
			} else {
				winner = "1 ";
			}
			winner += to_string(number_games);
			break;
		}
	}
    cout << winner << endl;
}