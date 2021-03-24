#include <iostream>
#define MAX 1000000007

using namespace std;
long long dp[101][101][101];
int N, L, R;

int f(int x, int y, int z) {
	dp[1][1][1] = 1;

	for (int i = 2; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			for (int k = 1; k <= z; k++) {
				dp[i][j][k] += dp[i - 1][j][k] * (i - 2) + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1];
				// i - 1번째의 배치에서 모든 번호를 1씩 증가시킨 후 맨 왼쪽에 1을 배치(dp[i - 1][j - 1][k])
				// 위와 동일하게 한 후 맨 오른쪽에 1을 배치(dp[i - 1][j][k - 1])
				// 위와 동일하게 한 후 맨 왼쪽과 오른쪽을 제외한 i - 2개에 배치(dp[i - 1][j][k] * (i - 2))
				dp[i][j][k] %= MAX;
			}
		}
	}

	return dp[x][y][z] % MAX;
}

int main() {
	cin >> N >> L >> R;
	cout << f(N, L, R);
}