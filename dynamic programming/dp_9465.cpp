#include <iostream>
#include <algorithm>

using namespace std;
long long score[2][100001];
long long dp[3][100001];

int main() {

	int K, T;

	cin >> K;
	for (int j = 0; j < K; j++) {
		cin >> T;
		for (int i = 1; i <= T; i++) {
			cin >> score[0][i];
		}

		for (int i = 1; i <= T; i++) {
			cin >> score[1][i];
		}

		dp[0][0] = dp[1][0] = dp[2][0] = 0;

		for (int i = 1; i <= T; i++) {
			dp[0][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));
			dp[1][i] = max(dp[2][i - 1], dp[0][i - 1]) + score[1][i];
			dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + score[0][i];
		}
		cout << max(dp[0][T], max(dp[1][T], dp[2][T])) << endl;

	}
	system("PAUSE");
	return 0;
}