#include <iostream>
#include <algorithm>

using namespace std;

bool check[100001];
int dp[100001];
int ldp[100001];
int rdp[100001];
int T;
int result = 0;


int main() {

	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >> dp[i];
	}

	if (T == 1) {
		cout << dp[1] << endl;
		return 0;
	}

	ldp[1] = dp[1];
	rdp[T] = dp[T];
	result = ldp[1];

	for (int i = 2; i <= T; i++) {
		ldp[i] = max(dp[i], ldp[i - 1] + dp[i]);
	}
	// 왼쪽 합 구하기

	for (int i = T - 1; i >= 1; i--) {
		rdp[i] = max(dp[i], rdp[i + 1] + dp[i]);
		// 오른쪽 합 구하기
	}

	for (int i = 1; i <= T; i++) {
		result = max(result, ldp[i]);
	}

	for (int i = 2; i <= T - 1; i++) {
		result = max(result, ldp[i - 1] + rdp[i + 1]);
		// 왼쪽합과 오른쪽 합을 더함(하나 빼고)
	}

	cout << result << endl;
	return 0;
}