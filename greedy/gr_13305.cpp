#include <iostream>

using namespace std;

long long n;
long long road[100001];
long long money[100001];
long long minm = 1000000000;
long long result = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> road[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> money[i];
	}

	for (int i = 0; i < n - 1; i++) {
		if (money[i] < minm) {
			minm = money[i];
		}
		result += road[i] * minm;
	}

	cout << result;
}