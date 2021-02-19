#include <iostream>
#include <queue>
#include <tuple>
#define MAX 1000
using namespace std;

int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, -1, 1 };
char map[MAX][MAX];
int visited[MAX][MAX];
int n, m;
int INT = 2000;
int result = INT;
queue<tuple<int, int, int>> q;


void maze() {
	q.push(make_tuple(0, 0, 1));

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int cnt = get<2>(q.front());

		if (x == n - 1 && y == m - 1)
			break;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int dx = x + X[k];
			int dy = y + Y[k];

			if (dx >= 0 && dx < n && dy >= 0 && dy < m) {

				if (map[dx][dy] == '0' && visited[dx][dy] != 1) {
					visited[dx][dy] = 1;
					q.push(make_tuple(dx, dy, cnt + 1));
				}
			}
		}
	}
	int a = get<0>(q.front());
	int b = get<1>(q.front());
	int c = get<2>(q.front());
	if (a == n - 1 && b == m - 1)
		result = min(c, result);
}

void clear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
}

void wall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '1') {
				map[i][j] = '0';
				clear();
				maze();
				map[i][j] = '1';
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	} 

	wall();

	if (result == INT)
		cout << "-1" << endl;
	else
		cout << result << endl;
	return 0;
}