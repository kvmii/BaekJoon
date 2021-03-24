#include <iostream>
#define MAX 1000000003;

using namespace std;
long long dp[1001][1001];
int n, k;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= 1000; i++) {
		dp[i][1] = i;
		dp[i][0] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MAX;
			// ���ڷ� ����ٰ� ���� �� ù��° ���� ���� �ι�° ���� �� ���� ������ i - 2���߿� j - 1���� ����
			// ���� ������ i - 1�� �߿� j���� ����
		}
	}

	cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % MAX;
	// �����̹Ƿ� �� �ڿ� �ִ� �͵� ���úҰ�
	// ó���� ���� n - 3�߿� k-1�� ����
	// ���� ������ n - 1���߿� k�� ����
}