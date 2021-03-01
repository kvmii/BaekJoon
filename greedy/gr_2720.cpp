#include <iostream>

using namespace std;

int q, d, n, p;

int main() {
	int T;
	cin >> T;

	while (T--)
	{
		q = d = n = p = 0;
		int money;
		cin >> money;
		while (money - 25 >= 0) {
			money -= 25;
			q++;
		}
		while (money - 10 >= 0) {
			money -= 10;
			d++;
		}
		while (money - 5 >= 0) {
			money -= 5;
			n++;
		}
		while (money - 1 >= 0) {
			money -= 1;
			p++;
		}

		cout << q << " " << d << " " << n << " " << p << endl;
	}
}