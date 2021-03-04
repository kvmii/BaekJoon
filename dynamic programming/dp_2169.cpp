#include <iostream>
#include <algorithm>

using namespace std;
int arr[1001][1001];
int dp[1001][1001];
int n, m;
int Left[1001];
// 오른쪽에서 왼쪽으로 방문
int Right[1001];
// 왼쪽에서 오른쪽으로 방문

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];

	for (int j = 1; j < m; j++) {
		dp[0][j] = arr[0][j] + dp[0][j - 1];
	}

	for (int i = 1; i < n; i++) {

		Right[0] = dp[i - 1][0] + arr[i][0];
		for (int j = 1; j < m; j++) {
			Right[j] = max(Right[j - 1], dp[i - 1][j]) + arr[i][j];
			// 오른쪽으로 가면서 큰 값 찾기
		}

		Left[m - 1] = dp[i - 1][m - 1] + arr[i][m - 1];
		for (int j = m - 2; j >= 0; j--) {
			Left[j] = max(Left[j + 1], dp[i - 1][j]) + arr[i][j];
			// 왼쪽으로 가면서 큰 값 찾기
		}

		for (int j = 0; j < m; j++) {
			dp[i][j] = max(Left[j], Right[j]);
			// 오른쪽, 왼쪽중에 큰 값
		}
	}

	cout << dp[n - 1][m - 1];
}