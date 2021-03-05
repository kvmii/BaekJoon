#include <iostream>
#include <cmath>

using namespace std;

int n, m, j;
int arr[20];
int num = 0;
int result = 0;

int main() {
	cin >> n >> m;
	// 문제 이해가 힘들었던 문제
	// 바구니의 크기가 m인 것이 중요
	cin >> j;

	for (int i = 0; i < j; i++) {
		cin >> arr[i];
	}

	num = 1;
	// 바구니의 제일 왼쪽을 바구니의 위치라고 생각
	for (int i = 0; i < j; i++) {
		if (arr[i] > num) {
			// 오른쪽에 있는 경우 m - 1만큼 덜 가도 된다
			int a = abs(arr[i] - num) - (m - 1);
			if (a >= 0) {
				// 이동할 경우
				result += a;
				num = arr[i] - m + 1;
			}
		}
		else {
			// 왼쪽에 있는 경우는 그냥 차이만큼 움직이면 된다
			result += abs(arr[i] - num);
			num = arr[i];
		}
	}

	cout << result << endl;
}