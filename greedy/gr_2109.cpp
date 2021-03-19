#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<pair<int, int>> vec;
int visited[10001];
int result = 0;

// 13904문제와 비슷
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a, b });
		// 점수, 일
	}

	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	// 높은 점수 순서로 정렬

	for (int i = 0; i < vec.size(); i++) {
		int score = vec[i].first;
		int cnt = vec[i].second;
		while (cnt >= 1) {
			if (visited[cnt] == 0) {
				// 해당일이 비어있다면
				visited[cnt] = score;
				result += score;
				break;
			}
			// 다른 일이 있으면 하루 빨리 실행
			cnt--;
		}
	}

	cout << result;

}