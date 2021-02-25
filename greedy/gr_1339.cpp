#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int arr[27];
int num, K = 9;
int result = 0;
vector<int> vec(26);

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		string str;
		cin >> str;
		int t = 1;
		for (int i = str.size() - 1; i >= 0; i--) {
			vec[str[i] - 'A'] += t;
			t *= 10;
		}
	}

	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());

	for (int i = 0; i < 26; i++) {
		if(vec[i] == 0){
			break;
		}
		result += K * vec[i];
		K--;
	}

	cout << result;
}