#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> vec;
int arr[1001];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ b, a });
	}

	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	// 점수가 높은 순으로 정렬

	for (int i = 0; i < vec.size(); i++) {
		int score = vec[i].first;
		int day = vec[i].second;

		if (arr[day] == 0) {
			// day날에 아무것도 안하면
			// 마감날짜에 맞춰서 제출
			arr[day] = score;
		}

		else {
			// 그날 다른 과제가 있다면
			while (day >= 1) {
				if (arr[day] == 0) {
					arr[day] = score;
					break;
					// 하루씩 줄여보면서 제출
				}
				day--;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 1001; i++) {
		result += arr[i];
	}

	cout << result;
}