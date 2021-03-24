#include <iostream>

using namespace std;
int n;
bool check = false;

int main() {
	cin >> n;
	int five = n / 5;
	int two = 0;
	while (1) {
		int num = n - five * 5;
		if (num % 2 == 0) {
			two = num / 2;
			break;
		}
		else five--;
		if (five < 0) {
			check = true;
			break;
		}
	}

	if (check == false)
		cout << five + two;
	else
		cout << -1;
}