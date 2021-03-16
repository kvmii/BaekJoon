#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;
int n, t;
int visited[101];
int homex, homey, endx, endy;
vector<pair <int, int>> gs;
bool check;

void bfs(int x, int y) {
	// bfs Ȱ��
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		int dx = q.front().first;
		int dy = q.front().second;
		q.pop();
		int d = abs(dx - endx) + abs(dy - endy);
		if (d <= 1000) {
			// �������� ������ �� ������
			check = true;
			return;
		}
		for (int i = 0; i < gs.size(); i++) {
			int distance = abs(dx - gs[i].first) + abs(dy - gs[i].second);
			if (visited[i] != 1 && distance <= 1000) {
				q.push({gs[i].first, gs[i].second});
				visited[i] = 1;
				// �� �� �ִ� �������� �湮
				// �� �������鿡�� �ٽ� ���
			}
		}
	}

}

int main() {
	cin >> t;
	while (t--) {
		check = false;
		memset(visited, 0, sizeof(visited));
		gs.clear();

		cin >> n;
		cin >> homex >> homey;
		// ������

		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			gs.push_back(make_pair(a, b));
		}
		cin >> endx >> endy;
		// ������

		bfs(homex, homey);
		if (check) cout << "happy\n";
		else cout << "sad\n";
	}


}        