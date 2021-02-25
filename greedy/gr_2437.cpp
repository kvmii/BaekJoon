#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;
int n;
int sum = 1;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		if (sum < arr[i]) {
			break;
		}
		// 내가 k를 측정 가능할 때 다음추 L이 k보다 작다면 k+1 ~ k + L까지 모두 측정 가능
		// 그러나 L이 크다면 k+1을 측정하지 못한다
		sum += arr[i];
	}

	cout << sum;
}