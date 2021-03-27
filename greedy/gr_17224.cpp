#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int k, n, l;
vector<pair<int, int>> vec;
int result = 0;

int main() {
	cin >> k >> n >> l;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ b,a });
	}

	sort(vec.begin(), vec.end());
	// 140점 기준으로 정렬

	int i = 0;
	while (1) {
		if (l == 0) break;
		// 다 풀었다면
		int num = vec[i].first;
		if (num > n) break;
		// 커지면 그 이후부터는 더 크기 때문에 풀수없다
		else {
			// 맞았으면 140점
			result += 140;
			i++;
			l--;
		}
	}

	while (1) {
		// 100점 짜리
		if (l == 0 || i == k) break;
		int num = vec[i].second;
		if (num <= n) {
			result += 100;
			i++;
			l--;
		}
		else {
			i++;
		}
	}
	cout << result;
}