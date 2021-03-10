#include <iostream>

using namespace std;
int n, m;
int arr[31];

int main() {
	cin >> n >> m;
	arr[n] = m;
	for (int i = m / 2; i <= m; i++) {
		// 하나씩 찾기
		arr[n - 1] = i;
		// 바로 전 수를 하나씩 대입
		for (int j = n - 2; j >= 1; j--) {
			arr[j] = arr[j + 2] - arr[j + 1];
			// 전부 구하기
		}
		bool check = false;
		for (int k = 1; k <= n; k++) {
			if (arr[k] < 0) {
				// 음수가 있다면
				check = true;
			}
			if (k != n && arr[k] > arr[k + 1]) {
				// A > B일 경우
				check = true;
			}
		}
		if (check == false) break;
	}

	cout << arr[1] << endl;
	cout << arr[2];
}