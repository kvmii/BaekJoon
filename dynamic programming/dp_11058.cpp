#include <iostream>

using namespace std;
long long dp[101];
int n;


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;

		// �ٿ��ֱ⸦ �ϱ� ���ؼ� ������ 2���� ������ �ʿ�
		for (int j = 2; j < i; j++) {
			dp[i] = max(dp[i], dp[j] * (i - j - 1));
			// j = i - 2���� ����
		}
	}

	cout << dp[n];
}