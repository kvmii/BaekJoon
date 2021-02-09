#include <iostream>

using namespace std;

int main() {
	long long dp[1001];

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i < 1001; i++) {
		dp[i] = (2 * dp[i - 2] + dp[i - 1]) % 10007;
	}

	int num;
	cin >> num;

	dp[num] = dp[num] % 10007;
	cout << dp[num];
}