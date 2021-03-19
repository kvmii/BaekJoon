#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, length;
vector<int> vec;

int main() {
	cin >> n >> length;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		if (length >= vec[i]) {
			length++;
		}
	}

	cout << length;
}