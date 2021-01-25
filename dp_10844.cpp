#include <iostream>

using namespace std;

int main() {
	long long dp[101][10];

	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}

	int n;
	cin >> n;
	int sum = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][1];
				// 뒷자리가 0인경우 전 숫자에서 1인경우와 같음
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][8];
				// 뒷자리가 9인경우 
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		sum = (sum + dp[n][i]) % 1000000000;
	}

	cout << sum;
}