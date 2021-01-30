#include <iostream>

using namespace std;

int dp[31];
int main() {

	dp[2] = 3;

	int T;
	cin >> T;

	for (int i = 4; i <= T; i += 2) {
		dp[i] += 3 * dp[i-2];
		for (int j = i - 4; j >= 2; j -= 2) {
			dp[i] += 2 * dp[j];
		}
		dp[i] += 2;
	}

	cout << dp[T] << endl;
}