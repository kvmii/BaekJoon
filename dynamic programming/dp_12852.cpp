#include <iostream>
#include <algorithm>

using namespace std;

int num;
int dp[1000001];
int result[1000001];

int solve(int n) {
	dp[1] = 0;

	for (int i = 2; i <= num; i++) {
		dp[n] = dp[n - 1] + 1;
		result[n] = n - 1;
		if (n % 3 == 0) {
			if (dp[n] > dp[n / 3] + 1) {
				dp[n] = dp[n / 3] + 1;
				result[n] = n / 3;
			}
		}
		if (n % 2 == 0) {
			if (dp[n] > dp[n / 2] + 1) {
				dp[n] = dp[n / 2] + 1;
				result[n] = n / 2;
			}
		}
	}
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cin >> num;
	int a = solve(num);
	cout << a << '\n';
	while (1) {
		cout << num << " ";
		num = result[num];
		if (num == 0) break;
	}
}
