#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
int n, m;
int visited[2001];
vector<int> vec[2001];
bool check = false;

void dfs(int x, int cnt) {
	if (cnt == 5) {
		// 연결된 개수가 5개면
		check = true;
		return;
	}
	visited[x] = 1;
	for (int i = 0; i < vec[x].size(); i++) {
		int idx = vec[x][i];
		if (visited[idx] != 1) {
			dfs(idx, cnt + 1);
		}
		if (check) return;
	}
	visited[x] = 0;
	// 다시 바꿔줘야 전부 탐색 가능
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i, 1);
		if (check) break;
	}
	if (check) cout << 1;
	else cout << 0;
}