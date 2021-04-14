#include <iostream>

using namespace std;
int dp[1001];
int arr[1001];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				// 증가하는 수열 문제
			}
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, dp[i]);
	}

	cout << result;
}