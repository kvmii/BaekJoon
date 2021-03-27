#include <iostream>
#include <deque>

using namespace std;
int T, n;

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		deque<char> dq;
		while (n--) {
			char c;
			cin >> c;
			if (dq.empty()) dq.push_back(c);
			else {
				if (c <= dq.front()) {
					dq.push_front(c);
				}
				else {
					dq.push_back(c);
				}
			}
		}
		while (!dq.empty()) {
			cout << dq.front();
			dq.pop_front();
		}
		cout << '\n';
	}
}