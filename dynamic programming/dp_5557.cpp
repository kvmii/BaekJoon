#include <iostream>

using namespace std;

long long arr[101];
long long dp[101][21];
int n;
int result = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[1][arr[0]] = 1;

	// dp[x][y] x는 몇 번째, y는 숫자
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= 20; j++) {

			if (dp[i - 1][j] > 0) {

				if (j + arr[i - 1] <= 20)
					dp[i][j + arr[i - 1]] += dp[i - 1][j];

				if (j - arr[i - 1] >= 0) {
					dp[i][j - arr[i - 1]] += dp[i - 1][j];
				}
			}
		}
	}

	// dfs로 했지만 시간초과로 dp로 변경
	// int 대신 long long
	cout << dp[n - 1][arr[n - 1]];
}