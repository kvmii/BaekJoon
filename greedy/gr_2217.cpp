#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
int result = 0;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());
	// 정렬

	for (int i = 0; i < vec.size(); i++) {
		int length = vec.size() - i;
		// 길이
		result = max(result, length * vec[i]);
		// 길이 * 값중에 제일 큰 것
	}

	cout << result << endl;
}