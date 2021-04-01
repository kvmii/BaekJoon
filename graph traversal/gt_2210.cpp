#include <iostream>
#include <set>

using namespace std;
set<int> result;
// set으로 중복 방지
int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, 1, -1 };
int arr[5][5];

void dfs(int a, int b, int num, int cnt) {
	if (cnt == 6) {
		// 6자리를 채웠다면
		result.insert(num);
		return;
	}

	for (int k = 0; k < 4; k++) {
		int dx = a + X[k];
		int dy = b + Y[k];
		if (dx < 0 || dy < 0 || dx >= 5 || dy >= 5) continue;

		dfs(dx, dy, num * 10 + arr[dx][dy], cnt + 1);
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 0, 0);
		}
	}

	cout << result.size();
	// 종류의 개수
}