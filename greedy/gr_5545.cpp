#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int dou, topping;
int price;
vector<int> vec;

int main() {
	cin >> n;
	cin >> dou >> topping;
	cin >> price;

	while (n--) {
		int a;
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end(), greater<int>());
	// ������ ū �ͺ��� ����

	int result = price / dou;
	// ������ ���� �ʾ��� ��
	int cal = price;
	for (int i = 0; i < vec.size(); i++) {
		// ������ 1��, 2��, ... i���� �� ������
		// ū �ͼ����� ������ �س��ұ� ������ ������� ������ �ȴ�
		cal += vec[i];
		dou += topping;
		result = max(result, cal / dou);
	}

	cout << result;
}