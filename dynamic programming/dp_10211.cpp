#include <iostream>

using namespace std;
int T, n;
int arr[1001];
int dp[1001];

int main() {
	cin >> T;
	while (T--) {

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		dp[1] = arr[1];
		for (int i = 2; i <= n; i++) {
			dp[i] = max(dp[i - 1], 0) + arr[i];
		}
		int result = -1001;
		for (int i = 1; i <= n; i++) {
			result = max(result, dp[i]);
		}
		cout << result << '\n';
	}
}