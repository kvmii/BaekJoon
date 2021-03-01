#include <iostream>
#include <queue>

using namespace std;
int x, y;
bool check = false;

void bfs(int x, int cnt) {
	queue<pair <int, int>>q;
	q.push({ x, cnt });
	while (!q.empty()) {
		int dx = q.front().first;
		int dy = q.front().second;
		q.pop();

		if (dx == y) {
			check = true;
			cout << dy;
			break;
		}

		int a = 2 * dx;
		int b = 10 * dx + 1;
		if(a <= y)
		q.push({ a, dy + 1 });
		if(b <= y && dx <= 100000000)
		q.push({ b, dy + 1 });
	}
}

int main() {
	cin >> x >> y;


	bfs(x, 1);

	if (!check) cout << -1;
}