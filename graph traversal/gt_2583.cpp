#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ground[101][101];
int visited[101][101];
int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, 1, -1 };
int n, m, k;
int result;
vector<int> vec;

void dfs(int x, int y) {
	visited[x][y] = 1;
	result++;

	for (int k = 0; k < 4; k++) {
		int dx = x + X[k];
		int dy = y + Y[k];

		if (dx < 0 || dx >= n || dy < 0 || dy >= m)
			continue;

		if (visited[dx][dy] != 1 && ground[dx][dy] != 1) {
			dfs(dx, dy);
		}
	}
}

int main() {
	cin >> m >> n >> k;
	// 상황에 맞게 m,n 구분 잘하기
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++) {
			for (int l = y1; l < y2; l++) {
				ground[j][l] = 1;
				// 직사각형 그리기
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] != 1 && ground[i][j] != 1) {
				// 직사각형이 없으면
				result = 0;
				dfs(i, j);
				vec.push_back(result);
				// 땅 개수만큼 vec에 push_back
			}
		}
	}

	sort(vec.begin(), vec.end());
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}

	system("PAUSE");
}