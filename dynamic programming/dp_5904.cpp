#include <iostream>
#include <string>

using namespace std;
long long dp[40];
long long n;

char solve(long long n) {
	if (n == 1) return 'm';
	// moo�� ����
	if (n == 2 || n == 3) return 'o';

	int i = 0;
	while (dp[i] < n) i++;
	if (dp[i] == n) return 'o';
	// ������ n��°�� ���ڸ��̹Ƿ� o
	if (n - dp[i - 1] == 1) return 'm';
	// 1ĭ ���̳��� ���ۺκ��̹Ƿ� m
	if (n - dp[i - 1] <= i + 3) return 'o';
	// o�� i + 3�� ��������Ƿ� �� �ȿ� �ִٸ� o
	else return solve(n - dp[i - 1] - i - 3);
	// �� �ܿ� ���
}

int main() {
	cin >> n;
	dp[0] = 3;
	for (int i = 1; i < 40; i++) {
		dp[i] = dp[i - 1] * 2 + i + 3;
		// ���ڿ� ����
	}

	cout << solve(n);
} 