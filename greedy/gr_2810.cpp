#include <iostream>
#include <string>

using namespace std;
string str;
int n;
int L;

int main(){
	cin >> n;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'L') {
			L++;
		}
	}

	int num = n + 1 - L / 2;

	if (num > n) num = n;
	cout << num;
}