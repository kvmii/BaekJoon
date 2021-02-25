#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> vec;
vector<int> vec2;
int n;
int result = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	// 큰 수부터 정렬

	for (int i = 0; i < vec.size(); i += 2) {
		if (i + 1 == vec.size()) {
			// 크기가 홀수여서 마지막 원소일 때
			if (vec[i] > 0)
				// 양수면
				result += vec[i];
			else vec2.push_back(vec[i]);
			// 음수면
			break;
		}

		if (vec[i] > 0 && vec[i + 1] > 0) {
			result += max(vec[i] * vec[i + 1], vec[i] + vec[i + 1]);
			// 둘다 양수면 두개씩 묶어서 더하기
		}

		if (vec[i + 1] <= 0) {
			// 두 번째 수가 음수일 때
			if (vec[i] <= 0) {
				// 둘다 음수면 vec2에 넣기
				vec2.push_back(vec[i]);
				vec2.push_back(vec[i + 1]);
			}
			else {
				// 양수, 음수면 양수는 더해주고 음수는 vec2에
				result += vec[i];
				vec2.push_back(vec[i + 1]);
			}
		}

	}

	sort(vec2.begin(), vec2.end());

	for (int i = 0; i < vec2.size(); i += 2) {
		if (i + 1 == vec2.size()) {
			result += vec2[i];
			break;
		}

		result += max(vec2[i] * vec2[i + 1], vec2[i] + vec2[i + 1]);
		// 음수끼리 곱하면 양수
	}

	cout << result;
}