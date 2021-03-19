#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> plusv;
vector<int> minusv;
int n, m;
int result = 0;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a >= 0) plusv.push_back(a);
		else minusv.push_back(-a);
		// 음수면 양수로 바꿔서 넣음
	}

	sort(plusv.begin(), plusv.end(), greater<int>());
	// 큰 순으로
	sort(minusv.begin(), minusv.end(), greater<int>());
	// 큰 순으로

	for (int i = 0; i < plusv.size(); i++) {
		if (i % m == 0) result += plusv[i] * 2;
		// m개씩 끊어서 왕복
	}
	for (int i = 0; i <	minusv.size(); i++) {
		if (i % m == 0) result += minusv[i] * 2;
		// m개씩 끊어서 왕복
	}

	if (plusv.empty()) {
		// 둘 중 하나가 비어있을 수 있다
		// 처음에 이거 생각 안해서 out of bounds가 발생
		result -= minusv[0];
	}
	else if (minusv.empty()) {
		result -= plusv[0];
		// 양수만 있다면
	}
	else {
		if (plusv[0] > minusv[0]) result -= plusv[0];
		// 다 가져다 놓기만 하면 끝이니 제일 멀리있는거 빼주기
		else result -= minusv[0];
	}
	cout << result;
}