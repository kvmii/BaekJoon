#include <iostream>

using namespace std;
int n, k;
int arr[1000001];
int visited[1000001];
int result = 0;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		if (arr[k + 1]) {
			// 앞에 높이가 1높은게 있었다면
			arr[k + 1]--;
			arr[k]++;
			// 높이 1 낮추기
		}
		else {
			// 없다면 k높이 추가
			arr[k]++;
			result++;
		}
	}

	cout << result;

}