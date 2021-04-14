#include <iostream>
#include <string.h>
#define MAX 987654321

using namespace std;
int n;
char arr[1001];
int dp[1001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	char next;
	fill(dp, dp + n, MAX);
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] == 'B') next = 'O';
		else if (arr[i] == 'O') next = 'J';
		else next = 'B';
		// 다음에 올 문자 정하기

		for (int j = i + 1; j < n; j++) {
			if (arr[j] == next) {
				// 다음에 올 문자면
				dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
				// 그 위치의 최솟값 찾기
			}
		}
	}

	if (dp[n - 1] == MAX) cout << -1;
	// 도착하지 못했다면
	else cout << dp[n - 1];
}