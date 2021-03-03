#include <iostream>
#include <queue>

using namespace std;

int result;
queue <pair <int, int>> q;
int visited[100001];

bool visit(int n) {
	if (n < 0 || n > 100000 || visited[n]) return false;
	return true;
}

void hide(int a, int b) {

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

int main() {
	int N, M;
	cin >> N >> M;
	q.push(make_pair(N, 1));
	hide(N, M);
	cout << result - 1;
}