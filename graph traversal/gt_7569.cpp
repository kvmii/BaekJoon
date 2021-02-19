#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int arr[101][101][101];
int X[] = { 1, -1, 0, 0, 0, 0 };
int Y[] = { 0, 0, 1, -1, 0, 0 };
int Z[] = { 0, 0, 0 , 0, 1, -1 };
int m, n, h;
bool zero = false;
queue<tuple<int, int, int>> q;


void bfs() {
	
	while (!q.empty()) {
		int a = get<0>(q.front());
		int b = get<1>(q.front());
		int c = get<2>(q.front());
		q.pop();

		for (int k = 0; k < 6; k++) {
			int dx = a + X[k];
			int dy = b + Y[k];
			int dz = c + Z[k];

			if (dx < 0 || dx >= n || dy < 0 || dy >= m || dz < 0 || dz >= h)
				continue;

			if (arr[dx][dy][dz] == 0) {
				arr[dx][dy][dz] = arr[a][b][c] + 1;
				q.push(make_tuple(dx, dy, dz));
			}
		}
	}
}

int main() {
	cin >> m >> n >> h;

	int num = 0;

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 0) {
					zero = true;
				}
				if (arr[i][j][k] == 1)
					q.push(make_tuple(i, j, k));
			}
		}
	}

	if (zero == false) {
		cout << "0";
		return 0;
	}

	bfs();

	zero = false;

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) { 
			for (int j = 0; j < m; j++) {
				if (arr[i][j][k] == 0) {
					zero = true;
				}
				if (num < arr[i][j][k])
					num = arr[i][j][k];
			}
		}
	}

	if (zero == true) {
	cout << "-1";
	return 0;
}
	else {
		cout << num - 1;
		return 0;
	}

}