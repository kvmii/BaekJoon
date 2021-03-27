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
				// }�� �������� ���
				// {�� �ٲٰ� ans++
				stk.push('{');
				ans++;
			}
			else if (str[i] == '}')
				stk.pop();
			// {�� �ִ� ���¿��� }�� ���� ���
			else
				stk.push('{');
			// {�� ���� ���� ���
		}
		ans += stk.size() / 2;
		// �ٲ�� �ϴ� ����
		cout << cnt << ". " << ans << "\n";
		cnt++;
	}
}