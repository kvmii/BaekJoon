#include <iostream>
#define MAX 1000000009

using namespace std;

int T, n;
long long dp[100001][3];
// 두 개의 수가 연속이 되면 안되므로 끝자리 수를 따로 계산
// 0 - 1로 끝남, 1 - 2로 끝남, 2- 3으로 끝남

int main() {
	dp[1][0] = 1;
	dp[2][1] = 1;
	dp[3][0] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;

	for (int i = 4; i <= 100000; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MAX;
		// 1로 끝날 경우 2나 3으로 끝나는 i -1 에다가 +1
		dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % MAX;
		dp[i][2] = (dp[i - 3][1] + dp[i - 3][0]) % MAX;
	}

	cin >> T;
	while (T--) {
		cin >> n;
		cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MAX << endl;
	}
}