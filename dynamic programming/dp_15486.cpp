#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long T;
	cin >> T;

	// 14501과 같은 문제(범위만 다름)
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
			// 남은 기간보다 ti가 길경우 상담을 못함
		}
		else {
			dp[i] = max(dp[i + 1], dp[i + ti[i]] + pi[i]);
			// ti가 짧을 경우 상담을 하는 것과 안하는 것중에 큰 것 선택
		}
	}

	cout << dp[1];

}