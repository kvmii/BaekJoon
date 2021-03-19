#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> vec;
int result = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end(), greater<int>());
	// 큰 순서로 정렬

	for (int i = 0; i < n; i++) {
		if (i % 3 == 2) continue;
		// 3번째마다 무시
		result += vec[i];
	}

	cout << result;
}