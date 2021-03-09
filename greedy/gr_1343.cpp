#include <iostream>
#include <string>

using namespace std;
string str;
string result;

int main() {
	cin >> str;
	int num = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'X') {
			num++;
		}
		if (str[i] == '.') {
			if (num % 2 != 0) {
				cout << -1;
				return 0;
			}
			else {
				int a = num / 4;
				int b = (num % 4) / 2;
				for (int i = 0; i < a; i++) {
					result += "AAAA";
				}
				for (int i = 0; i < b; i++) {
					result += "BB";
				}
				num = 0;
			}
			result += ".";
		}
		if (i == str.size() - 1) {
			if (num % 2 != 0) {
				cout << -1;
				return 0;
			}
			int a = num / 4;
			int b = (num % 4) / 2;
			for (int i = 0; i < a; i++) {
				result += "AAAA";
			}
			for (int i = 0; i < b; i++) {
				result += "BB";
			}
		}
	}

	cout << result;
}