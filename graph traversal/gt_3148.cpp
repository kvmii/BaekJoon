#include <iostream>
#include <queue>

using namespace std;
int n, m;
char arr[251][251];
int visited[251][251];
int X[] = { 1, -1, 0 ,0 };
int Y[] = { 0, 0, 1, -1 };
int sheep = 0, wolf = 0;
int s = 0, w = 0;

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	visited[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (arr[x][y] == 'o') sheep++;
		// ���̸�
		else if (arr[x][y] == 'v') wolf++;
		// �����
		for (int k = 0; k < 4; k++) {
			int dx = x + X[k];
			int dy = y + Y[k];
			if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
			if (arr[dx][dy] != '#' && visited[dx][dy] != 1) {
				// ��Ÿ���� �ƴϸ� �Ѿ��
				q.push({ dx, dy });
				visited[dx][dy] = 1;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] != 1 && arr[i][j] != '#') {
				sheep = 0;
				wolf = 0;
				bfs(i, j);
				// ���̶� ���� �� �Ǻ�
				if (sheep > wolf) {
					s += sheep;
				}
				else {
					w += wolf;
				}
			}
		}
	}

	cout << s << " " << w;
}