#include <iostream>
#include <queue>

using namespace std;

int result;
queue <pair <int, int>> q;
int visited[100001];

bool visit(int n) {
	if (n < 0 || n > 100000 || visited[n]) return false;
	return true;
}

void hide(int a, int b) {

	while (!q.empty()) {
		int x = q.front().first;
		// x는 숫자
		int y = q.front().second;
		// y는 몇초가 지났는지
		q.pop();
		if (x == b) {
			result = y;
			break;
		}
		if (visit(x + 1)) {
			q.push(make_pair(x + 1, y + 1));
			visited[x + 1] = true;
		}
		if (visit(x - 1)) {
			q.push(make_pair(x - 1, y + 1));
			visited[x - 1] = true;
		}
		if (visit(2 * x)) {
			q.push(make_pair(x * 2, y + 1));
			visited[2 * x] = true;
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	q.push(make_pair(N, 1));
	hide(N, M);
	cout << result - 1; 
	system("PAUSE");
}
// 처음에 제출했을 때 메모리초과가 생겼다
// 중복된 숫자 방문과 100000이라는 숫자를 넘는 경우가 생겨서 그런 것 같다