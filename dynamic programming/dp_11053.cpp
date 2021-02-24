#include <iostream>

using namespace std;

int n;
int arr[1001];
int dp[1001];
int num = 1;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				num = max(num, dp[i]);
			}
		}
	}

	cout << num << endl;
}