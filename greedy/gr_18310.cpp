#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> vec;


int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());

	cout << vec[(n - 1) / 2];
}