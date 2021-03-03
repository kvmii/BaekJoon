#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> vec[50];
int root[50];
// 자식의 개수
int visited[50];
// 방문 여부
int parent[50];
// 부모 노드
int n, k;

int bfs(int x) {
	// bfs 활용
	// 리프노드의 개수 찾기
	if (root[x] == 0) return 1;
	visited[x] = 1;
	int score = 0;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int cnt = q.front();
		q.pop();
		if (root[cnt] == 0) score++;
		// 자식이 없으면
		for (int i = 0; i < vec[cnt].size(); i++) {
			if (visited[vec[cnt][i]] != 1) {
				visited[vec[cnt][i]] = 1;
				q.push(vec[cnt][i]);
			}
		}
	}

	return score;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == -1) continue; 
		vec[a].push_back(i);
		root[a]++;
		parent[i] = a;
	}

	cin >> k;

	int result = 0;

	root[parent[k]]--;
	// 없어지는 노드의 부모의 자식 수--
	// 이게 0이 되면 리프노드가 추가 된다

	for (int i = 0; i < n; i++) {
		if (root[i] == 0) result++;
	}

	cout << result - bfs(k);
	// 없어지는 노드의 리프노드 개수 빼기
}