#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
int visited[1001][1001];
int n, result;

void bfs(int x) {
	queue<tuple<int, int,int>> q;
	// 값, 몇 초, 복사한 값
	q.push({ x, 1, 1 });
	visited[x][1] = 1;
	while (!q.empty()) {
		int num = get<0>(q.front());
		int cnt = get<1>(q.front());
		int copy = get<2>(q.front());
		q.pop();

		if (num == n) {
			result = cnt;
			break;
		}

		int board = num;
		if (visited[num][board] != 1 && num <= 1000) {
			q.push({ num, cnt + 1, board });
		}

		int dy = num - 1;

		int dz = num + copy;
		if (dy > 0 && dy <= 1000 && visited[dy][copy] != 1) {
			q.push({ dy, cnt + 1, copy });
			visited[dy][copy] = 1;
		}

		if (dz > 0 && dz <= 1000 && visited[dz][copy] != 1) {
			q.push({ dz, cnt + 1 , copy});
			visited[dz][copy] = 1;
		}
	}
}

int main() {
	cin >> n;
	bfs(1);
	 
	cout << result;
}