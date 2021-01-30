#include <iostream>
#include <algorithm>

using namespace std;
int dp[1001][1001];
int str[1001][1001];


int main() {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> str[i][j];
		}
	}

	dp[0][0] = str[0][0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = str[i][0] + dp[i - 1][0];
	}

	for (int i = 1; i < m; i++) {
		dp[0][i] = str[0][i] + dp[0][i - 1];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + str[i][j];
		}
	}
	
	cout << dp[n - 1][m - 1];
	system("PAUSE");
}