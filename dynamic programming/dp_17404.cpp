#include <iostream>

using namespace std;
int arr[1001][3];
int dp[1001][3];
int n;
int result = 987654321;

// 1149와 유사하지만 이 문제는 원형이다
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	for (int k = 0; k < 3; k++) {
		// 하나씩 비교
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 0) {
					if (j == k) dp[0][j] = arr[0][j];
					else dp[0][j] = result;
					// 하나씩 비교하기 위해 나머지 값들은 MAX로 채움
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
			if (i == k) continue;
			// 도착지와 출발지가 같다면
			if (result > dp[n - 1][i]) {
				result = dp[n - 1][i];
			}
		}
	}



	cout << result;
}