#include <iostream>

using namespace std;
long long dp[31][31];
// �˾ళ��, �� �˾ళ��
int n;

int main() {
	for (int i = 0; i < 31; i++) {
		dp[0][i] = 1;
		//����¥���� �ִٸ� ����Ǽ� 1����
	}

	for (int i = 1; i <= 30; i++) {
		for (int j = 0; j <= 30; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1];
				// ����¥���� ������ �ϳ� �����
			}
			else {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j + 1];
				//�ϳ��� �ɰ��� ���ʸ���� + ���ʸԱ�
			}
		}
	}

	while (1) {
		cin >> n;
		if (n == 0) break;
		cout << dp[n - 1][1] << endl;
	}
}