#include <iostream>

using namespace std;

int m, n, T, K;
int arr[101][101];
int visited[101];
int result = 0;

void virus(int x) {
	visited[x] = 1;

	for (int i = 1; i <= T; i++) {
		if (arr[i][x] == 1 && visited[i] != 1) {
			result++;
			virus(i);
		}
	}
}

int main() {
	cin >> T;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> m >> n;
		arr[m][n] = 1;
		arr[n][m] = 1;
	}

	virus(1);
	cout << result;
	system("PAUSE");
}