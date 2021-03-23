#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
int n, m;
int arr[501][501];
int result = 0;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		// a < b;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (arr[j][i] == 1 && arr[i][k] == 1) {
					arr[j][k] = 1;
					// j < i °í i < k¸é j < k
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		bool check = false;
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				if (arr[i][j] != 1 && arr[j][i] != 1) {
					check = true;
					break;
				}
			}
		}
		if (check == false) result++;
	}

	cout << result;
}