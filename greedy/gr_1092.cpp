#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
int n, m;
vector<int> arr;
vector<int> crain;
int visited[10001];
int check[21];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end(), greater<int>());
	// 오름차순 정렬

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		crain.push_back(a);
	}

	sort(crain.begin(), crain.end(), greater<int>());
	// 오름차순 정렬

	if (arr[0] < crain[0]) {
		// 제일 무거운게 크레인 보다 크면
		cout << -1;
		return 0;
	}

	int score = 0;

	while (!crain.empty()) {
		// 무거운 것 부터 차례대로 크레인에 대입
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < crain.size(); j++) {
				if (arr[i] >= crain[j]) {
					crain.erase(crain.begin() + j);
					break;
				}
			}
		}
		// 크레인 3개를 다 사용하면 score++;
		score++;
	}

	cout << score;
}