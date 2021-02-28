#include <iostream>

using namespace std;
int a[46];
int b[46];
int n;

int main() {
	a[0] = 1;
	b[0] = 0;

	for (int i = 1; i <= 45; i++) {
		a[i] = b[i - 1]; 
		if (a[i] < 0) a[i] = 0;
		b[i] = b[i - 1] + a[i - 1];
	}

	cin >> n;
	cout << a[n] << " " << b[n] << endl;
}