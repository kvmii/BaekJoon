#include <iostream>

using namespace std;
int n, m;
int result;

int main() {
	cin >> n >> m;

	if (n == 1) {
		result = 1;
	}

	if (n == 2) {
		if (m >= 7)
			result = 4;
		else {
			result = (m + 1) / 2;
		}
	}

	if (n >= 3) {
		if (m <= 3 && m >= 1)
			result = m;

		if (m >= 4 && m <= 6) result = 4;

		if (m > 6) {
			result = m - 2;
		}
	}

	// 문제 조건이 이해하기 힘들었던 문제
	// 직접 그려보고 이해했다
	cout << result;
}