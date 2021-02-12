#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
char dp[25][25];
int result;
int visited[25][25];
int X[] = { -1, 1, 0, 0 }, Y[] = { 0, 0, -1, 1 };
int num = 0;
vector<int> vec;

void maze(int a, int b) {

	visited[a][b] = 1;
	result++;

	for (int k = 0; k < 4; k++) {
		int dx = a + X[k];
		int dy = b + Y[k];
		if (dx < 0 || dx >= n || dy < 0 || dy >= n)
			continue;

		if (dp[dx][dy] == '1' && visited[dx][dy] != 1) {
			maze(dx, dy);
		}
	}

}



int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> dp[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == '1' && visited[i][j] != 1) {
				result = 0;
				maze(i, j);
				vec.push_back(result);
			}
		}
	}

	sort(vec.begin(), vec.end());

	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	
	system("PAUSE");
}