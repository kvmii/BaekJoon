#include <iostream>

using namespace std;
int dp[4][50001];
int n, m;
int s[50001];

int solve(int x, int y) {
	if (x == 3) return 0;
	// 3개 다 운행했으면
	if (y >= n) return 0;
	// 크기보다 커지면
	int& ret = dp[x][y];
	if (ret) return ret;
	// 이 칸을 끌고 갈 경우
	// 앞의 m칸까지 같이 끌고 같다
	if (y + m >= n) {
		ret += s[n] - s[y] + solve(x + 1, y + m);
		// m칸 뒤가 n보다 클 때
	}
	else {
		ret += s[y + m] - s[y] + solve(x + 1, y + m);
		// 앞의 m칸까지의 합 + 재귀
	}
	ret = max(ret, solve(x, y + 1));
	// 이 칸을 끌고 가지 않을 경우
	// 다음칸으로 이동
	return ret;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (i == 1) s[i] = a;
		else s[i] = s[i - 1] + a;
	}
	cin >> m;
	cout << solve(0, 0);
}