#include <iostream>
#include <string>

using namespace std;


int dp[200][200][200];

int main() {
	string str1, str2, str3;
	cin >> str1 >> str2 >> str3;
	// 2개를 먼저 비교하고 나머지를 비교했으나 오답
	// 3차원으로 해결

	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			for (int k = 1; k <= str3.length(); k++) {
				if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else {
					int a = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
					int b = max(dp[i - 1][j - 1][k], max(dp[i][j - 1][k - 1], dp[i - 1][j][k - 1]));
					dp[i][j][k] = max(a, b);
				}
			}
		}
	}
	int num1 = str1.length();
	int num2 = str2.length();
	int num3 = str3.length();


	cout << dp[num1][num2][num3];
}