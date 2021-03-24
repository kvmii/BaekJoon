#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long T;
	cin >> T;

	// 14501�� ���� ����(������ �ٸ�)
	long long ti[1500001];
	long long pi[1500001];
	long long dp[1500001];

	for (int i = 1; i <= T; i++) {
		cin >> ti[i] >> pi[i];
	}

	dp[T + 1] = 0;

	for (long long i = T; i > 0; i--) {
		if (ti[i] > T - i + 1) {
			dp[i] = dp[i + 1];
			// ���� �Ⱓ���� ti�� ���� ����� ����
		}
		else {
			dp[i] = max(dp[i + 1], dp[i + ti[i]] + pi[i]);
			// ti�� ª�� ��� ����� �ϴ� �Ͱ� ���ϴ� ���߿� ū �� ����
		}
	}

	cout << dp[1];

}