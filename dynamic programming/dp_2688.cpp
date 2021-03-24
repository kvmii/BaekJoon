#include <iostream>

using namespace std;
long long dp[65][10];
// [�ڸ���][�� ������ ��]
int T, n;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cin >> T;
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i < 65; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				// �۰ų� ���� �͵��� ��� �����ش�
			}
		}
	}
	while (T--) {
		cin >> n;
		long long result = 0;
		for (int i = 0; i < 10; i++) {
			result += dp[n][i];
			// 0~9�� ������ n�ڸ��� ���ϱ�
		}
		cout << result << '\n';
	}
}