#include <iostream>
#include <string.h>

using namespace std;
int n;
int Left[2000];
int Right[2000];
int dp[2000][2000];

int card(int x, int y) {
	if (x >= n || y >= n) return 0;
	if (dp[x][y] != -1) return dp[x][y];

	if (Right[y] < Left[x]) dp[x][y] = (card(x, y + 1) + Right[y]);
	// 작으면 오른쪽 카드를 버리기
	else dp[x][y] = (max(card(x + 1, y), card(x + 1, y + 1)));
	// 아니면 둘다 버리기 or 왼쪽 버리기

	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> Left[i];
	for (int i = 0; i < n; i++) cin >> Right[i];
	memset(dp, -1, sizeof(dp));

	cout << card(0, 0);
}