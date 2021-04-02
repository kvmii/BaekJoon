#include <iostream>

using namespace std;
int dp[4][50001];
int n, m;
int s[50001];

int solve(int x, int y) {
	if (x == 3) return 0;
	// 3�� �� ����������
	if (y >= n) return 0;
	// ũ�⺸�� Ŀ����
	int& ret = dp[x][y];
	if (ret) return ret;
	// �� ĭ�� ���� �� ���
	// ���� mĭ���� ���� ���� ����
	if (y + m >= n) {
		ret += s[n] - s[y] + solve(x + 1, y + m);
		// mĭ �ڰ� n���� Ŭ ��
	}
	else {
		ret += s[y + m] - s[y] + solve(x + 1, y + m);
		// ���� mĭ������ �� + ���
	}
	ret = max(ret, solve(x, y + 1));
	// �� ĭ�� ���� ���� ���� ���
	// ����ĭ���� �̵�
	return ret;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (i == 1) s[i] = a;
		else s[i] = s[i - 1] + a;
	}
	cin >> m;
	cout << solve(0, 0);
}