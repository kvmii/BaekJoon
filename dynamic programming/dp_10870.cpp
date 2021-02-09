#include <iostream>

using namespace std;

int main() {
	long long dp[21];

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= 20; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int num;
	cin >> num;
	cout << dp[num];

	system("PAUSE");

	return 0;
}