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
		// ������ ����� �ٲ㼭 ����
	}

	sort(plusv.begin(), plusv.end(), greater<int>());
	// ū ������
	sort(minusv.begin(), minusv.end(), greater<int>());
	// ū ������

	for (int i = 0; i < plusv.size(); i++) {
		if (i % m == 0) result += plusv[i] * 2;
		// m���� ��� �պ�
	}
	for (int i = 0; i <	minusv.size(); i++) {
		if (i % m == 0) result += minusv[i] * 2;
		// m���� ��� �պ�
	}

	if (plusv.empty()) {
		// �� �� �ϳ��� ������� �� �ִ�
		// ó���� �̰� ���� ���ؼ� out of bounds�� �߻�
		result -= minusv[0];
	}
	else if (minusv.empty()) {
		result -= plusv[0];
		// ����� �ִٸ�
	}
	else {
		if (plusv[0] > minusv[0]) result -= plusv[0];
		// �� ������ ���⸸ �ϸ� ���̴� ���� �ָ��ִ°� ���ֱ�
		else result -= minusv[0];
	}
	cout << result;
}