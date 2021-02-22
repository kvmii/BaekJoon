#include <iostream>

using namespace std;

int money;
int arr[] = { 500, 100, 50, 10, 5, 1 };
int result = 0;

int main() {
	cin >> money;
	money = 1000 - money;

	int i = 0;

	while (money != 0) {
		int num = money / arr[i];
		if (num > 0) {
			money = money - num * arr[i];
			result += num;
			i++;
		}
		else i++;
	}

	cout << result;
}