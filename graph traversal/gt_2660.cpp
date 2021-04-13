#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
int visited[51];
vector<int> vec[51];
int score[51];
int n;

int bfs(int x) {
	queue<int> q;
	visited[x] = 1;
	q.push(x);
	while (!q.empty()) {
		int dx = q.front();
		q.pop();
		for (int i = 0; i < vec[dx].size(); i++) {
			int s = vec[dx][i];
			if (!visited[s]) {
				q.push(s);
				visited[s] = visited[dx] + 1;
			}
		}
	}
	int score = 0;
	for (int i = 1; i <= n; i++) {
		score = max(score, visited[i]);
	}
	return score - 1;
}

int main() {
	cin >> n;
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		score[i] = bfs(i);
	}
	int result = 987654321;
	for (int i = 1; i <= n; i++) {
		result = min(result, score[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (score[i] == result) cnt++;
	}

	cout << result << " " << cnt << endl;
	for (int i = 1; i <= n; i++) {
		if (score[i] == result) cout << i << " ";
	}
}