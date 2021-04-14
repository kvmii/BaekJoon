#include <iostream>
#include <string>

using namespace std;
long long dp[40];
long long n;

char solve(long long n) {
	if (n == 1) return 'm';
	// moo로 시작
	if (n == 2 || n == 3) return 'o';

	int i = 0;
	while (dp[i] < n) i++;
	if (dp[i] == n) return 'o';
	// 같으면 n번째는 끝자리이므로 o
	if (n - dp[i - 1] == 1) return 'm';
	// 1칸 차이나면 시작부분이므로 m
	if (n - dp[i - 1] <= i + 3) return 'o';
	// o가 i + 3개 만들어지므로 그 안에 있다면 o
	else return solve(n - dp[i - 1] - i - 3);
	// 그 외에 재귀
}

int main() {
	cin >> n;
	dp[0] = 3;
	for (int i = 1; i < 40; i++) {
		dp[i] = dp[i - 1] * 2 + i + 3;
		// 문자열 길이
	}

	cout << solve(n);
} 