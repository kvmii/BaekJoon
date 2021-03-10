#include <iostream>

using namespace std;
int result = 0;
int arr[101][101];

int main() {
	int n = 4;
	int x1, y1, x2, y2;
	while (n--) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				if (arr[i][j] == 0) {
					result++;
					arr[i][j] = 1;
				}
			}
		}
	}

	cout << result;
}