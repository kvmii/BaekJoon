#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string arr;
int result = 0;
int result2 = 0;

int main() {
	
	cin >> arr;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == '0') {
			if(arr[i + 1] == '1') result++;
		}
		if (arr[i] == '1' && i == 0) result++;
		if (arr[i] == '1') {
			if (arr[i + 1] == '0') result2++;
		}
		if (arr[i] == '0' && i == 0) result2++;
	}

	cout << min(result, result2);
}