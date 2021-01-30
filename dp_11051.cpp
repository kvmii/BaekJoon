#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long dp[1001][1001];

	int a, b;
	cin >> a >> b;

	for (int i = 0; i <= a; i++) {
		dp[i][i] = 1;
		dp[i][0] = 1;
	}
	for (int i = 2; i <= a; i++) {
		for (int j = 1; j <= a; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}

	cout << dp[a][b] % 10007 << endl;
}