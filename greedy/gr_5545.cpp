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
	// 열량이 큰 것부터 정렬

	int result = price / dou;
	// 토핑을 넣지 않았을 때
	int cal = price;
	for (int i = 0; i < vec.size(); i++) {
		// 토핑을 1개, 2개, ... i개를 다 따진다
		// 큰 것순으로 정렬을 해놓았기 때문에 순서대로 따지면 된다
		cal += vec[i];
		dou += topping;
		result = max(result, cal / dou);
	}

	cout << result;
}