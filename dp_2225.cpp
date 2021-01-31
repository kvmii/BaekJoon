#include <iostream>

using namespace std;

long long dp[201][201];

int n, k;

int main() {


	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		dp[i][1] = 1;
	}

	for (int l = 2; l <= k; l++) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= i; j++) {
				dp[i][l] += dp[j][l - 1];
			}
			dp[i][l] = dp[i][l] % 1000000000;
		}
	}

	cout << dp[n][k] << endl;
	system("PAUSE");
}