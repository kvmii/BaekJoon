#include <iostream>
#include <vector>
#include <queue>
#define MAX 20000
using namespace std;

vector<int> vec[MAX + 1];
bool check[MAX + 1] = { 0, };
int visited[MAX + 1];
int K, V, E, u, v;

void dfs(int s, int color) {
	check[s] = true;
	visited[s] = color;
	for (int i = 0; i < vec[s].size(); i++) {
		int nxt = vec[s][i];
		if (check[nxt]) continue;
		dfs(nxt, -color);
	}
}

void clear(int n) {
	for (int i = 0; i <= n; i++) {
		vec[i].clear();
		check[i] = 0;
		visited[i] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> K;
	while (K--) {
		bool a = true;
		cin >> V >> E;
		while (E--) {
			cin >> u >> v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		for (int i = 1; i <= V; i++) {
			if (visited[i] == 0) {
				dfs(i, 1);
			}
		}

		for (int i = 1; i <= V; i++) {
			for (int j = 0; j < vec[i].size(); j++) {
				int nxt = vec[i][j];
				if (visited[i] == visited[nxt]) a = false;
			}
		}
		if (a) cout << "YES" << "\n";
		else cout << "NO" << "\n";
		clear(V);
	}
}