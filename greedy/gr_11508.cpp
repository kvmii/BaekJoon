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
	// ū ������ ����

	for (int i = 0; i < n; i++) {
		if (i % 3 == 2) continue;
		// 3��°���� ����
		result += vec[i];
	}

	cout << result;
}