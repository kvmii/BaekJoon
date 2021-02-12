#include <iostream>
#include <queue>


using namespace std;

int n, m;
int num = 0;
int arr[1001][1001];
bool zero = false;
int X[] = { -1, 1, 0, 0 }, Y[] = { 0, 0, -1, 1 };
queue <pair<int, int>> q;

// bfs 활용
void bfs() {
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int dx = cur.first + X[k];
			int dy = cur.second + Y[k];
			if (dx < 0 || dx >= n || dy < 0 || dy >= m)
				continue;

			if (arr[dx][dy] == 0) {
				arr[dx][dy] = arr[cur.first][cur.second] + 1;
				q.push(make_pair(dx, dy));
			}
		}
	}

}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)
				zero = true;
		}
	}

	// 전부 1 or -1이면 (0이 없으면) 0 반환
	if (zero == false){
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				// 전부 익지 않았으면(0이 하나라도 있으면)
				cout << -1 << endl;
				return 0;
			}
			if (num < arr[i][j])
				num = arr[i][j];
		}
	}
	cout << num - 1 << endl;
	return 0;
}