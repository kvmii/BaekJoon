#include <iostream>

using namespace std;
int arr[1001][3];
int dp[1001][3];
int n;
int result = 987654321;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 0) {
				dp[i][j] = arr[i][j];
			}

			else {
				if (j == 0) {
					dp[i][j] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][j];
				}
				else if (j == 1) {
					dp[i][j] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][j];
				}
				else if (j == 2) {
					dp[i][j] = min(dp[i - 1][1], dp[i - 1][0]) + arr[i][j];
				}
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		if (result > dp[n - 1][i]) {
			result = dp[n - 1][i];
		}
	}

	cout << result;
}