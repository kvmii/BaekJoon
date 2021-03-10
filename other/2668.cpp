#include <iostream>
#include <queue>
#include <vector>]
#include <string.h>

using namespace std;
int n;
int arr[101];
int visited[101];
vector<int> vec;

int bfs(int x) {
	queue<int> q;
	q.push(x);
	visited[x] = 1;
	while (!q.empty()) {
		int dx = q.front();
		q.pop();
		int dy = arr[dx];
		if (x == dy) return 1;
		if (visited[dy] != 1) {
			q.push(dy);
			visited[dy] = 1;
		}
	}
	return -1;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		if (bfs(i) == 1) {
			vec.push_back(i);
		}
		memset(visited, 0, sizeof(visited));
	}

	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
}