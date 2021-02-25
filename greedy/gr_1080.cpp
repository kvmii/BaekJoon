#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
char a[51][51];
char b[51][51];
int n, m;
int result = 0;

void flip(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (a[i][j] == '0')
				a[i][j] = '1';
			else a[i][j] = '0';
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}

	if (n < 3 || m < 3) {
		// 3x3보다 작을 때
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != b[i][j]) {
					cout << "-1";
					return 0;
					// 다르면 -1출력
				}
			}
		}
		cout << "0";
		// 같으면 0출력
		return 0;
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] != b[i][j]) {
				result++;
				flip(i, j);
				// 3x3 뒤집기
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				cout << "-1";
				return 0;
			}
		}
	}

	cout << result;
}