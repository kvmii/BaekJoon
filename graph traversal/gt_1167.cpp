#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;
int visited[100001];
vector<pair<int, int>> vec[100001];
int n;
int result = 0;
int com;

// 1967과 유사한 문제. 똑같이 풀었다가 시간초과가 발생
// 트리의 지름을 구할 때 하나씩 길이를 다 구해서 제일 긴것을 찾는 것이 비효율적이었다
// 아무점에서 시작해서 제일 먼 점을 구한 후 그 점에서 제일 먼 점까지의 길이 = 트리의 지름이라는 팁을 찾고 해결

void bfs(int x) {
	queue<pair<int, int>> q;
	q.push({ x,0 });
	visited[x] = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < vec[a].size(); i++) {
			// a 와 연결된 원소들
			int cnt = vec[a][i].first;
			if (visited[cnt] != 1) {
				visited[cnt] = 1;
				// 길이 더해주기
				q.push({ cnt, vec[a][i].second + b });
			}
		}

		if (result < b) {
			result = b;
			com = a;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a;
		while(1){
			cin >> b;
			if (b == -1) break;
			cin >> c;
		vec[a].push_back({ b,c });
		// a 와 연결된 b 그 길이 c
		}
	}

	bfs(1);
	// 1에서 제일 먼 점 찾기
	int num = com;
	// 점의 좌표
	memset(visited, 0, sizeof(visited));
	result = 0;

	bfs(num);
	// 그 점에서 길이 구하기

	cout << result;
}