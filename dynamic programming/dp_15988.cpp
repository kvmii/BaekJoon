#include <iostream>
using namespace std;

long long dp[1000001];
long long n, T;

int main() {

	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 1000000; i++) {
		dp[i] = ((dp[i - 1] + dp[i - 2]) % 1000000009 + dp[i - 3]) % 1000000009;
	}

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}