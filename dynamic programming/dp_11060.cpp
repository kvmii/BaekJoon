#include <iostream>

using namespace std;

int arr[1000];
int dp[1000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = -1;
	}

	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= arr[i]; j++) {
			if (dp[i + j] == -1) {
				if (dp[i] == -1) continue;
				dp[i + j] = dp[i] + 1;
			}
			else {
				dp[i + j] = min(dp[i + j], dp[i] + 1);
			}
		}
	}

	if (dp[n - 1] == -1) {
		cout << -1;
	}
	else
	cout << dp[n - 1];
}