#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[50];

int main() {
	cin >> n;

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i < 50; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vector<int> vec;

		while (num != 0) {
			int i = 0;
			while (1) {
				if (arr[i] > num)  {
					num -= arr[i - 1];
					vec.push_back(arr[i - 1]);
					break;
				}
				i++;
			}
		}
		reverse(vec.begin(), vec.end());
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " ";
		}
		cout << endl;
	}
}