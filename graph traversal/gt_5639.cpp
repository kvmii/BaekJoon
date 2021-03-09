#include <iostream>
#include <vector>

using namespace std;
vector<int> arr;

void print(int x, int y) {
	if (x > y) return; 

	int root = arr[x];
	int cnt = y;
	while (arr[cnt] > root) cnt--;
	// 오른쪽 자식 찾기

	print(x + 1, cnt);
	// 왼쪽에서 다시
	print(cnt + 1, y);
	// 오른쪽에서 다시

	cout << root << endl;
}

int main() {
	int a;
	while (cin >> a) {
		arr.push_back(a);
		// 입력 받기
	}

	print(0, arr.size() - 1);
	return 0;
}