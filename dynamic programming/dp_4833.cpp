#include <iostream>
#include <string.h>

using namespace std;

long long dp[100001][3];
long long arr[100001][3];
int k, n;

int main() {
	k = 1;
	while (1) {
		cin >> n;
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		// �ʱ�ȭ ���ֱ�
		if (n == 0) break;
		// 0 �Է¹����� ��
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> arr[i][j];
			}
		}

		dp[0][2] = arr[0][1] + arr[0][2];
		dp[1][0] = arr[0][1] + arr[1][0];
		// ��� �������� ����
		dp[1][1] = min(dp[0][2], min(dp[1][0], arr[0][1])) + arr[1][1];
		dp[1][2] = min(dp[0][2], min(dp[1][1], arr[0][1])) + arr[1][2];

		for (int i = 2; i < n; i++) {
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][0];
			// ���� ������ �Ʒ� �ƴϸ� �밢��
			dp[i][1] = min(min(dp[i - 1][0], dp[i - 1][1]), min(dp[i - 1][2], dp[i][0])) + arr[i][1];
			// ����� ����, �밢��, �Ʒ� �� 4����
			dp[i][2] = min(min(dp[i - 1][1], dp[i - 1][2]), dp[i][1]) + arr[i][2];
			// �������� ����, �Ʒ�, �밢�� 3����
		}

		cout << k << ". " << dp[n - 1][1] << '\n';
		// ���� ������ ������ �ּڰ�
		k++;
	}
}