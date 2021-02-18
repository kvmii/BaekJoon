#include <iostream>

using namespace std;

int dp[1001];

int main() {
	int T;
	cin >> T;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;

	for (int i = 4; i < 1001; i++) {
		if (dp[i - 3] == 0)
			dp[i] = 1;
		else if (dp[i - 3] == 1)
			dp[i] = 0;
	}

	if (dp[T] == 0)
		cout << "SK";
	if (dp[T] == 1)
		cout << "CY";
}