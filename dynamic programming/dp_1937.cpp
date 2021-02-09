#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int dp[500][500];
int result[500][500];
int x[] = { -1, 1, 0, 0 }, y[] = { 0, 0, -1, 1 };
int num = 0;

int panda(int a, int b) {
	// 재귀함수
	if (result[a][b] != 0)
		return result[a][b];

	result[a][b] = 1; // 1로 초기화

	for(int k = 0; k < 4; k++) {
		int dx = a + x[k];
		int dy = b + y[k];
		if (dx < 0 || dx >= n || dy < 0 || dy >= n)
			continue;

		if (dp[dx][dy] > dp[a][b]) 
			result[a][b] = max(panda(dx,dy) + 1, result[a][b]);
	}

	return result[a][b];
}

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dp[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			num = max(panda(i, j), num);
		}
	}

	cout << num;
}