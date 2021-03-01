#include <iostream>

using namespace std;
int arr[30000];
int n;
int result = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		int score = 0;
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				score++;
			}
			else {
				break;
			}
		}
		if (result < score) { result = score; }
	}

	cout << result;
}