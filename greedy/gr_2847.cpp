#include <iostream>

using namespace std;

int n;
int arr[101];
int result = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = n - 1; i >= 1; i--) {
		while (1) {
			if (arr[i] < arr[i + 1]) break;
			arr[i]--;
			result++;
		}
	}

	cout << result;
}