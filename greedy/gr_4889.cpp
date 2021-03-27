#include <iostream>
#include <stack>
#include <string>

using namespace std;
int n;
bool check;

int main() {
	int cnt = 1;
	while(1) {
		string str;
		cin >> str;
		if (str[0] == '-') return 0;

		stack<char> stk;

		int ans = 0;
		for (int i = 0; i < str.length(); i++) {
			if (stk.empty() && str[i] == '}') {
				// }가 먼저나올 경우
				// {로 바꾸고 ans++
				stk.push('{');
				ans++;
			}
			else if (str[i] == '}')
				stk.pop();
			// {가 있는 상태에서 }가 나올 경우
			else
				stk.push('{');
			// {가 먼저 나올 경우
		}
		ans += stk.size() / 2;
		// 바꿔야 하는 개수
		cout << cnt << ". " << ans << "\n";
		cnt++;
	}
}