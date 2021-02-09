#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	long p[101] = { 0 };

	int num;

	p[1] = 1;
	p[2] = 1;
	p[3] = 1;


	for (int i = 4; i < 101; i++) {
		p[i] = p[i - 2] + p[i - 3];
	}

	for (int i = 0; i < T; i++) {
		cin >> num;
		cout << p[num] << endl;
	}

}