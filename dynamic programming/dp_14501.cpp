#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	int ti[16];
	int pi[16];
	int dp[16];

	for (int i = 1; i <= T; i++) {
		cin >> ti[i] >> pi[i];
	}

	dp[T + 1] = 0;

	for (int i = T; i > 0; i--) {
		if (ti[i] > T - i + 1) {
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + 1], dp[i + ti[i]] + pi[i]);
		}
	}

	cout << dp[1];

	system("PAUSE");
}