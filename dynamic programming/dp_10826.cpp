#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string arr[10001];

string change(string str1, string str2) {
	long long sum = 0;
	string result;

	// 문자열로 더하기
	// 2407과 비슷
	while (!str1.empty() || !str2.empty() || sum) {
		if (!str1.empty()) {
			sum += str1.back() - '0';
			str1.pop_back();
		}

		if (!str2.empty()) {
			sum += str2.back() - '0';
			str2.pop_back();
		}

		result.push_back((sum % 10) + '0');

		sum /= 10;

	}
	reverse(result.begin(), result.end());
	return result;
}

int main() {
	arr[0] = '0';
	arr[1] = '1';
	for (int i = 2; i <= 10000; i++) {
		arr[i] = change(arr[i - 1], arr[i - 2]);
	}

	int n;
	cin >> n;
	cout << arr[n];
}