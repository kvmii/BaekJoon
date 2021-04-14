#include <iostream>

using namespace std;
int T, n;
int dp[10001][4];

int main() {
	cin >> T;
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;

	for (int i = 4; i <= 10000; i++) {
		dp[i][1] = dp[i - 1][1];
		//1로 끝날 경우 1밖에 못붙임
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		// 1이나 2로 끝날경우 2를 붙일 수 있음
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
		// 1,2,3으로 끝날 경우 3을 붙일 수 있음
	}

	while (T--) {
		cin >> n;
		cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
	}
}