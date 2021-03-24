#include <iostream>
#include <string.h>

using namespace std;
int T, n;
int card[1001];
int dp[1001][1001][2];

int solve(int s, int e, bool t) {
	if (s == e) {
		if (t) return card[s];
		// �����ʸ� ���� ī�� ������
		else return 0;
	}

	int& ret = dp[s][e][t];
	if (ret != -1) return ret;

	if (t) ret = max(solve(s + 1, e, !t) + card[s], solve(s, e - 1, !t) + card[e]);
	// �� ���ʸ� �ִ��� ũ�� ������ ��´�
	else ret = min(solve(s + 1, e, !t), solve(s, e - 1, !t));
	// ��� ���ʸ� ������ �ּ��� ������ �ش�

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