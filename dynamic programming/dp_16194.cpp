#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1001];
int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], dp[j] + dp[i - j]);
		}
	}

	cout << dp[n];
}