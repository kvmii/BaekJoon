#include <iostream>

using namespace std;
int n;
double arr[10001];
double result = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		double score = 1;
		for (int j = i; j <= n; j++) {
			score *= arr[j];
			if (result < score) result = score;
		}
	}

	cout << fixed;
	cout.precision(3);
	cout << result;
	return 0;
}