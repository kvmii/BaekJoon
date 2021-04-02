#include <iostream>

using namespace std;
int n;
int dp[21][101];
int health[21];
int joy[21];

int solve(int x, int y) {
	// ���, ü��
	if (dp[x][y]) return dp[x][y];
	int& ret = dp[x][y];
	if (x == n) return 0;
	// �� ����������

	if (y - health[x] > 0) {
		ret = solve(x + 1, y - health[x]) + joy[x];
		// �Ǽ� �ϱ�
	}

	ret = max(ret, solve(x + 1, y));
	// �Ǽ� ���ϰ� ��������
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> health[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> joy[i];
	}

	cout << solve(0, 100);
}