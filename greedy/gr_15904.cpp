#include <iostream>
#include <string>

using namespace std;
int u, c, p;
bool check;
int visited[4];

int main() {
	string str;
	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'U') {
			u = i;
			visited[0] = 1;
			break;
		}
	}

	for (int i = u; i < str.size(); i++) {
		if (str[i] == 'C') {
			c = i;
			visited[1] = 1;
			break;
		}
	}

	for (int i = c; i < str.size(); i++) {
		if (str[i] == 'P') {
			p = i;
			visited[2] = 1;
			break;
		}
	}

	for (int i = p; i < str.size(); i++) {
		if (str[i] == 'C') {
			visited[3] = 1;
			break;
		}
	}

	if (visited[0] && visited[1] && visited[2] && visited[3]) {
		check = true;
	}

	if (check) cout << "I love UCPC" << endl;
	else cout << "I hate UCPC" << endl;
}