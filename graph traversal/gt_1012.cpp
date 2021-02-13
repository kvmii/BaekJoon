#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, T, m, k;
int dp[50][50];
int result;
int visited[50][50];
int X[] = { -1, 1, 0, 0 }, Y[] = { 0, 0, -1, 1 };
int num = 0;
vector<int> vec;

void cab(int a, int b) {

	visited[a][b] = 1;
	result++;

	for (int k = 0; k < 4; k++) {
		int dx = a + X[k];
		int dy = b + Y[k];
		if (dx < 0 || dx >= n || dy < 0 || dy >= m)
			continue;

		if (dp[dx][dy] == 1 && visited[dx][dy] != 1) {
			cab(dx, dy);
		}
	}

}

void clear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}


int main(void) {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> m >> n >> k;

		int sum = 0;
		clear();

		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			dp[b][a] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dp[i][j] == 1 && visited[i][j] != 1) {
					result = 0;
					cab(i, j);
					if (result != 0)
						sum++;
				}
			}
		}

		cout << sum << endl;
		system("PAUSE");
	}
}