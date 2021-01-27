#include <iostream>

using namespace std;


long long dp[31][31];
int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {

		for (int i = 0; i <= 30; i++) {
			dp[i][i] = 1;
			dp[i][0] = 1;
		}

		int m, n;
		cin >> m >> n;


		for (int i = 2; i <= 30; i++) {
			for (int j = 1; j <= i; j++) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}

		cout << dp[n][m] << endl;
	}
	return 0;
}