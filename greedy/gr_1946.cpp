#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int T, n;
int result;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;

		vector<pair<int, int>> vec;

		for (int j = 0; j < n; j++) {
			int a, b;
			cin >> a >> b;
			vec.push_back(make_pair(a, b));
		}

		sort(vec.begin(), vec.end());
		result = 1;
		int ranking = vec[0].second;

		for (int k = 1; k < n; k++) {
			if (vec[k].second < ranking) {
				result++;
				ranking = vec[k].second;
			}
		}
		cout << result << endl;
	}

	return 0;
	// 시간초과가 발생했던 문제
	// 처음에는 정렬한 후 하나씩 비교 -> 시간초과
	// 제일 높은 등수를 저장해 놓고 그거보다만 높으면 추가하는 식으로 변경 -> 시간초과 해결
}