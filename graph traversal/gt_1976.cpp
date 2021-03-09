#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
int visited[201];
int arr[1001];
int n, m;
vector<int> vec[201];
bool check = true;

int bfs(int x, int y) {
	// 연결되었는지 확인해주는 함수
	if (x == y) {
		return 1;
	}
	queue<int> q;
	q.push(x);
	visited[x] = 1;
	while (!q.empty()) {
		int dx = q.front();
		q.pop();
		for (int i = 0; i < vec[dx].size(); i++) {
			// dx와 연결된 길
			int dy = vec[dx][i];
			if (dy == y) {
				return 1;
				break;
				// y와 연결되었다면
			}
			if (visited[dy] != 1) {
				q.push(dy);
				visited[dy] = 1;
			}
		}
	}
	return -1;
}

int main() {
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				vec[i].push_back(j);
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < m; i++) {
		if (bfs(arr[i], arr[i + 1]) == -1) {
			check = false;
			// 연결이 되지 않았으면
		}
		memset(visited, 0, sizeof(visited));
		// 초기화
	}
	if (check)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}