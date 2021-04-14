#include <iostream>
#define MAX 1234567

using namespace std;

int dp[1001][10];
// 자리수, 무슨 숫자로 끝나는지
int T, n;

int main() {
	cin >> T;
	for (int i = 0; i < 10; i++) dp[0][i] = 1;
	for (int i = 1; i < 1001; i++) {
		dp[i][0] = dp[i - 1][7] % MAX;
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][4]) % MAX;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5]) % MAX;
		dp[i][3] = (dp[i - 1][2] + dp[i - 1][6]) % MAX;
		dp[i][4] = (dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7]) % MAX;
		dp[i][5] = (dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8]) % MAX;
		dp[i][6] = (dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9]) % MAX;
		dp[i][7] = (dp[i - 1][0] + dp[i - 1][4] + dp[i - 1][8]) % MAX;
		dp[i][8] = (dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9]) % MAX;
		dp[i][9] = (dp[i - 1][6] + dp[i - 1][8]) % MAX;
		// 각 다이얼마다 이어진 것만 dp
	}
	while (T--) {
		cin >> n;

		long long result = 0;
		for (int i = 0; i < 10; i++) result += dp[n-1][i] % MAX;
		cout << result % MAX << '\n';
	}
}