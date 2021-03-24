#include <iostream>
#include <string.h>

using namespace std;
int n;
int result = 0;
int dp[50001];

int main() {
	cin >> n;
	memset(dp, 10000, sizeof(dp));
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (j * j == i) dp[i] = 1;
			// 제곱수라면 1번
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n];
}