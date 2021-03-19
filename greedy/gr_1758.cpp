#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> vec;
long result = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end(), greater<int>());

	for (int i = 0; i < vec.size(); i++) {
		vec[i] -= i;
		if (vec[i] > 0) {
			result += vec[i];
		}
	}

	cout << result;
}
