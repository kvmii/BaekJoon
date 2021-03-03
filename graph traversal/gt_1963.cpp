#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
int arr[10000];
int visited[10000];
int num[4];

int bfs(int x, int y) {
	queue <pair<int, int>> q;
	q.push({ x, 0 });
	visited[x] = 1;
	while (!q.empty()) {
		int dx = q.front().first;
		int dy = q.front().second;
		q.pop();

		if (dx == y) return dy;

		for (int i = 0; dx != 0; i++) {
			num[i] = dx % 10;
			dx /= 10;
		}

		for (int i = 0; i <= 9; i++) {
			int first = i * 1000 + num[2] * 100 + num[1] * 10 + num[0];
			int second = i * 100 + num[3] * 1000 + num[1] * 10 + num[0];
			int third = i * 10 + num[2] * 100 + num[3] * 1000 + num[0];
			int fourth = num[2] * 100 + num[1] * 10 + num[3] * 1000 + i;
			if (visited[first] != 1 && arr[first] == 0 && i != 0) {
				q.push({ first, dy + 1 });
				visited[first] = 1;
			}
			if (visited[second] != 1 && arr[second] == 0) {
				q.push({ second, dy + 1 });
				visited[second] = 1;
			}
			if (visited[third] != 1 && arr[third] == 0) {
				q.push({ third, dy + 1 });
				visited[third] = 1;
			}
			if (visited[fourth] != 1 && arr[fourth] == 0) {
				q.push({ fourth, dy + 1 });
				visited[fourth] = 1;
			}
		}
	}
	return -1;
}

int main() {
	for (int i = 2; i < 10000; i++) {
		if (arr[i] == 1) continue;
		for (int j = i + i; j < 10000; j += i) {
			arr[j] = 1;
		}
	}
	int T;
	cin >> T;
	while (T--) {
		memset(visited, 0, sizeof(visited));
		int a, b;
		cin >> a >> b;
		int result = bfs(a, b);
		if (result != -1) cout << result << endl;
		else cout << "Impossible" << endl;
	}
}