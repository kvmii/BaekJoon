#include <iostream>

using namespace std;

int main() {
	int L, P, V;
	int i = 1;
	while (1) {
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)
			break;

		int a = V / P;
		int b = V % P;
		int result;
		if (b <= L)
			result = L * a + b;

		else result = L * (a + 1);

		cout << "Case " << i << ": " << result << endl;
		i++;
	}
}