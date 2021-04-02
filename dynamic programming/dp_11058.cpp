#include <iostream>

using namespace std;
long long dp[101];
int n;


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;

		// 붙여넣기를 하기 위해선 무조건 2번의 연산이 필요
		for (int j = 2; j < i; j++) {
			dp[i] = max(dp[i], dp[j] * (i - j - 1));
			// j = i - 2까지 진행
		}
	}

	cout << dp[n];
}