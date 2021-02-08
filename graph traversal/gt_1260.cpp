#include <iostream>
#include <queue>

using namespace std;

queue<int> que;
int n, m, t;
int graph[1001][1001] = { 0 };
int visited[1001] = { 0 };

void dfs(int v) {
	cout << v << " ";
	visited[v] = 1;

	for (int i = 1; i <= n; i++) {
		if (graph[v][i] && visited[i] != 1) {
			visited[i] = 1;
			dfs(i);
			// Àç±Í
		}
	}

	return;
}

void bfs(int v) {
	que.push(v);
	visited[v] = 1;

	while (!que.empty()) {
		int num = que.front();
		cout << num << " ";
		que.pop();

		visited[num] = 1;
		for (int i = 1; i <= n; i++) {
			if (graph[num][i] && visited[i] != 1) {
				visited[i] = 1;
				que.push(i);
			}
		}
	}
}

int main() {
	cin >> n >> m >> t;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	dfs(t);
	cout << endl;

	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}

	bfs(t);
	cout << endl;
}