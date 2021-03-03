#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;
int visited[10001];
vector<pair<int, int>> vec[10001];
int n;
int result = 0;

void bfs(int x) {
	queue<pair<int, int>> q;
	q.push({ x,0 });
	visited[x] = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for(int i = 0; i < vec[a].size(); i++){
			// a 와 연결된 원소들
			int cnt = vec[a][i].first;
			if (visited[cnt] != 1) {
				visited[cnt] = 1;
				// 길이 더해주기
				q.push({cnt, vec[a][i].second + b});
			}
		}

		if (result < b) {
			result = b;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
		// a 와 연결된 b 그 길이 c
		vec[b].push_back({ a,c });
	}

	int score = 0;

	for (int i = 1; i <= n; i++) {
		bfs(i);
		if (score < result)
			score = result;
		result = 0;
		// 제일 길이가 긴것 찾기
		memset(visited, 0, sizeof(visited));
	}

	cout << score;
}