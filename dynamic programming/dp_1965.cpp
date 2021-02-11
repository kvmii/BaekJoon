#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1001];
int num = 0;

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> arr[i];
	}
	// 가장 긴 증가하는 수열 문제와 똑같다

	for (int i = 1; i <= T; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		num = max(num, dp[i]);
	}

	cout << num;
}