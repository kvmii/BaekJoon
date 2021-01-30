#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int dp[1000001];
	dp[1] = 1;

	int T, sqrt = 2;
	cin >> T;

	for (int i = 2; i <= T; i++) {
		if (i == sqrt * sqrt) {
			dp[i] = 1;
			sqrt++;
		}
		else {
			dp[i] = dp[i - 1] + 1;
			for (int j = 1; j < sqrt; j++) {
				int x = j * j;
				dp[i] = min(dp[i], dp[x] + dp[i - x]);
			}
		}
	}
	cout << dp[T];
}

