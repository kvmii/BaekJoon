#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

string str;
int n, m;
char dp[500][500];
int result[500][500];
int visited[500][500];
int X[] = { -1, 1, 0, 0 }, Y[] = { 0, 0, -1, 1 };
int num = 0;

int maze(int a, int b) {
	// bfs

	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	visited[a][b] = 1;
	result[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int dx = x + X[k];
			int dy = y + Y[k];
			if (dx < 0 || dx >= n || dy < 0 || dy >= m)
				continue;

			if (dp[dx][dy] == '1' && visited[dx][dy] != 1) {
				visited[dx][dy] = 1;
				result[dx][dy] = result[x][y] + 1;
				q.push(make_pair(dx, dy));
			}
		}
	
	}
	return result[n - 1][m - 1];

}

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> dp[i];
	}

	cout << maze(0, 0);
	system("PAUSE"); 
}