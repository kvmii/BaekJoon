#include <iostream>

using namespace std;

int arr[16][16];
int n, result = 0;

void dfs(int x, int y, int cnt) {
	//좌표, 상태
	//cnt 0가로 1대각선 2세로
	if (x == n - 1 && y == n - 1) {
		result++;
		// 도착하면 ++
		return;
	}

	if (arr[x][y] != 1) {
		if (cnt == 2) {
			// 세로일 때 세로와 대각선
			if (x + 1 < n && arr[x + 1][y] != 1)
				dfs(x + 1, y, 2);
			if (x + 1 < n && y + 1 < n && arr[x + 1][y+1] != 1 && arr[x + 1][y] != 1 && arr[x][y + 1] != 1)
				dfs(x + 1, y + 1, 1);
		}
		else if (cnt == 1) {
			// 대각선일 때 가로, 세로, 대각선
			if (x + 1 < n && arr[x + 1][y] != 1)
				dfs(x + 1, y, 2);
			if (x + 1 < n && y + 1 < n && arr[x + 1][y + 1] != 1 && arr[x + 1][y] != 1 && arr[x][y + 1] != 1)
				dfs(x + 1, y + 1, 1);
			if (y + 1 < n && arr[x][y + 1] != 1)
				dfs(x, y + 1, 0);
		}
		else if (cnt == 0) {
			// 가로일 때 가로, 대각선
			if (y + 1 < n && arr[x][y + 1] != 1)
				dfs(x, y +1, 0);
			if (x + 1 < n && y + 1 < n && arr[x + 1][y + 1] != 1 && arr[x + 1][y] != 1 && arr[x][y + 1] != 1)
				dfs(x + 1, y + 1, 1);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 1, 0);

	cout << result << endl;
}