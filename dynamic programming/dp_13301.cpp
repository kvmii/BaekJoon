#include <iostream>

using namespace std;
long long  dp[81];

int main() {
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= 80; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int n;
	cin >> n;
	if (n == 1) cout << 4;
	else cout << 4 * dp[n] + 2 * dp[n - 1];
}