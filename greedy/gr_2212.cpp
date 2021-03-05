#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> vec;
vector<int> arr;
int n, k;
int score = 0;
int result;

int main() {
	cin >> n;
	cin >> k;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());

	if (n == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i < vec.size(); i++) {
		int a = vec[i] - vec[i - 1];
		arr.push_back(a);
		score += a;
	}

	int x = score;
	result = score;

	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());

	for (int i = 1; i <= k; i++) {
		int num = i - 1;
		score = x;
		for (int j = 0; j < num; j++) {
			score -= arr[j];
		}
		result = min(result, score);
	}

	cout << result;
}