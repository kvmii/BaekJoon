#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int result;
int visited[100001];
int N, M;
int res = 0;

bool visit(int n) {
	if (n < 0 || n > 100000 || visited[n]) return false;
	return true;
}

void hide(int a, int b) {
	queue <pair <int, int>> q;
	q.push({ N, 0 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == b) {
			result = y;
			break;
		}
		if (visit(x + 1)) {
			q.push(make_pair(x + 1, y + 1));
			visited[x + 1] = true;
		}
		if (visit(x - 1)) {
			q.push(make_pair(x - 1, y + 1));
			visited[x - 1] = true;
		}
		if (visit(2 * x)) {
			q.push(make_pair(x * 2, y + 1));
			visited[2 * x] = true;
		}
	}
}


void bfs(int a, int b) {
	queue <pair <int, int>> q;
	q.push({ N, 0 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visited[x] = 1;
		// 방문처리를 여기서 해주어야 중복이 가능
		if (y == result && x == b) {
			res++;
		}
		if (y > result) break;
		// 최소시간을 넘어갈 경우
		if (visit(2 * x)) {
			q.push(make_pair(x * 2, y + 1));
		}
		if (visit(x + 1)) {
			q.push(make_pair(x + 1, y + 1));
		}
		if (visit(x - 1)) {
			q.push(make_pair(x - 1, y + 1));
		}
	}
}

int main() {
	cin >> N >> M;
	hide(N, M);
	cout << result << endl;
	memset(visited, 0, sizeof(visited));
	bfs(N, M);
	cout << res;
}