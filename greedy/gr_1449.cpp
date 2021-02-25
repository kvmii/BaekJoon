#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
int N, L;
int minm;
int result = 1;

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());

	minm = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] - minm >= L) {
			// 사이 거리가 테이프보다 길면
			minm = vec[i];
			result++;
		}
	}

	// 2437과 비슷한 문제
	cout << result;
}