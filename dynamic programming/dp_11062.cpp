#include <iostream>
#include <string.h>

using namespace std;
int T, n;
int card[1001];
int dp[1001][1001][2];

int solve(int s, int e, bool t) {
	if (s == e) {
		if (t) return card[s];
		// 내차례면 남는 카드 가져감
		else return 0;
	}

	int& ret = dp[s][e][t];
	if (ret != -1) return ret;

	if (t) ret = max(solve(s + 1, e, !t) + card[s], solve(s, e - 1, !t) + card[e]);
	// 내 차례면 최대한 크게 점수를 얻는다
	else ret = min(solve(s + 1, e, !t), solve(s, e - 1, !t));
	// 상대 차례면 나에게 최소의 점수를 준다

	return ret;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			cin >> card[i];
		}
		cout << solve(1, n, true) << '\n';
	}
}