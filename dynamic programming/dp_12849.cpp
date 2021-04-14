#include <iostream>
#define MOD 1000000007

using namespace std;

int n;
long long dp[100001][8];
// 0 - 정보과학관, 1- 전산관, 2 - 미래관, 3 - 신양관, 4 - 한경직, 5 - 진리관, 6 - 학생회관, 7 - 형남공학관

int main() {
	cin >> n;

	dp[1][1] = 1;
	dp[1][2] = 1;
	for (int i = 2; i <= n; i++) {
		// 서로 연결된 곳 확인
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][0] + dp[i - 1][3] + dp[i - 1][4]) % MOD;
		dp[i][3] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][5]) % MOD;
		dp[i][4] = (dp[i - 1][3] + dp[i - 1][2] + dp[i - 1][5] + dp[i - 1][7]) % MOD;
		dp[i][5] = (dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][6]) % MOD;
		dp[i][6] = (dp[i - 1][5] + dp[i - 1][7]) % MOD;
		dp[i][7] = (dp[i - 1][4] + dp[i - 1][6]) % MOD;
	}

	cout << dp[n][0] % MOD;
} 