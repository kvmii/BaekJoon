#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, k;
vector<int> vec;

int main() {
	cin >> n >> m >> k;
	if (n < m + k - 1 || n > m * k) {
		// 성립이 불가능할 때
		cout << -1;
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		vec.push_back(i);
	}

	reverse(vec.begin(), vec.begin() + k);
	// 처음에 k만큼 뒤집어 주면 감소하는 수열은 k개로 성립
	// 그리고 전체를 m개로 나눈 뒤 전부 뒤집어 주면 된다.

	int cnt = k;


	for (int i = 1; i < m; i++) {
		int idx = cnt;

		cnt += (n - cnt) / (m - i);
		// 남은 수 / 증가하는 수열에서 남은 것

		reverse(vec.begin() + idx, vec.begin() + cnt);
		// 뒤집기
	}

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
}