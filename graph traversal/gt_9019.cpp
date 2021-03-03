#include <iostream>
#include <queue>
#include <string>
#include <string.h>

using namespace std;
int visited[10001];
int a, b;
int T;

string bfs(int x, int y) {
	queue<pair<int, string>> q;
	q.push({ x, "" });
	visited[x] = 1;
	while (!q.empty()) {
		int dx = q.front().first;
		string str = q.front().second;
		q.pop();

		if (dx == y) return str;

		int D = 2 * dx;
		if (D > 9999)
			D = D % 10000;
		int S;
		if (dx == 0) S = 9999;
		else S = dx - 1;
		int L, R;
		if (dx / 1000 >= 1) {
			L = (dx % 1000) * 10 + dx / 1000;
			R = (dx % 10) * 1000 + dx / 10;
		}
		else if (dx / 100 >= 1) {
			L = dx * 10;
			R = (dx % 10) * 1000 + dx / 10;
		}
		else if (dx / 10 >= 1) {
			L = dx * 10;
			R = (dx % 10) * 1000 + dx / 10;
		}
		else {
			L = dx * 10;
			R = dx * 1000;
		}

		if (visited[D] != 1) {
			visited[D] = 1;
			q.push({ D, str + "D" });
		}

		if (visited[S] != 1) {
			visited[S] = 1;
			q.push({ S, str + "S" });
		}

		if (visited[L] != 1) {
			visited[L] = 1;
			q.push({ L, str + "L" });
		}

		if (visited[R] != 1) {
			visited[R] = 1;
			q.push({ R, str + "R" });
		}
	}
}

int main() {
	cin >> T;
	while (T--) {
		cin >> a >> b;
		cout << bfs(a, b) << endl;
		memset(visited, 0, sizeof(visited));
	}
}