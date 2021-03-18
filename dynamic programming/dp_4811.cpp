#include <iostream>

using namespace std;
long long dp[31][31];
// 알약개수, 반 알약개수
int n;

int main() {
	for (int i = 0; i < 31; i++) {
		dp[0][i] = 1;
		//반쪽짜리만 있다면 경우의수 1가지
	}

	for (int i = 1; i <= 30; i++) {
		for (int j = 0; j <= 30; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1];
				// 반쪽짜리가 없을때 하나 만들기
			}
			else {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j + 1];
				//하나를 쪼개서 반쪽만들기 + 반쪽먹기
			}
		}
	}

	while (1) {
		cin >> n;
		if (n == 0) break;
		cout << dp[n - 1][1] << endl;
	}
}