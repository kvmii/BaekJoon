#include<iostream>
#include <algorithm>

int INF = 1000000007;
using namespace std;

int dp[501][501];
int cost[501];
int sum[501];
int T, K, i;

int main() {
	cin >> T;
	while (T--) {
		cin >> K;
		for (i = 1; i <= K; ++i) {
			cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}

		for (int i = 1; i < K; i++) {
			for (int j = 1; j + i <= K; j++) {
				int d = j + i;
				dp[j][d] = INF;

				for (int k = j; k < d; k++)
					dp[j][d] = min(dp[j][d], dp[j][k] + dp[k + 1][d] + sum[d] - sum[j - 1]);
			}
		}

		cout << dp[1][K] << endl;
	}
	return 0;
}
