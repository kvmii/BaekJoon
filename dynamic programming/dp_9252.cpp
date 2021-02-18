#include <iostream>
#include <string>

using namespace std;

string lcs[1001][1001];

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	// lcs 구할 때 표를 이해하면 편함

	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + str1[i - 1];
				// 같을 경우 왼쪽 아래 방향에서 + 1
			}
			else {
				if (lcs[i][j - 1].length() <= lcs[i - 1][j].length())
					lcs[i][j] = lcs[i - 1][j];
				else
					lcs[i][j] = lcs[i][j - 1];
			}
		}
	}

	int num1 = str1.length();
	int num2 = str2.length();

	cout << lcs[num1][num2].length() << endl;
	cout << lcs[num1][num2] << endl;
}