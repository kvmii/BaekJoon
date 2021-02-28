#include <iostream>
#include <string>

using namespace std;

int lcs[4001][4001];

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	int max = 0;
	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
				// 연속된 같은 문자를 찾음
			}
			if (lcs[i][j] > max) {
				max = lcs[i][j];
			}
		}
	}

	cout << max << endl;
}