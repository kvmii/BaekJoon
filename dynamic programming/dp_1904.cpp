#include <iostream>

using namespace std;

int main() {
	long long dp[10000001];

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	int T;
	cin >> T;
	for (int i = 3; i <= T; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[T];
}