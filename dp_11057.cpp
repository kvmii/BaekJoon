#include <iostream>

using namespace std;

int main() {
	long long dp[1001][10] = { 0, };
	// 안될 때는 초기화

	int T;
	cin >> T;
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	// dp[i][j] = dp[i - 1][0] + ... + dp[i - 1][j]
	for (int i = 2; i <= T; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 10007;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += dp[T][i];
		ans %= 10007;
	}
	cout << ans;

}