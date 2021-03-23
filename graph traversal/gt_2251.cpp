#include <iostream>
#include <queue>

using namespace std;
int A, B, C;
int visited[201][201];
int result[201];

struct three {
	int x, y, z;
};

void bfs(int x,int y, int z) {
	queue<three> q;
	q.push({ x,y,z });
	visited[x][y] = 1;
	while (!q.empty()) {
		int a = q.front().x;
		int b = q.front().y;
		int c = q.front().z;
		q.pop();
		visited[a][b] = 1;
		if (a == 0) result[c] = 1;
		// a -> b
		if (a + b > B) {
			if (visited[a + b - B][B] != 1) q.push({ a + b - B, B, c });
		}
		else {
			if (visited[0][b + a] != 1) q.push({ 0, b + a, c });
		}
		// b -> a
		if (a + b > A) {
			if (visited[A][a + b - A] != 1) q.push({ A, a + b - A, c });
		}
		else {
			if (visited[b + a][0] != 1) q.push({ b + a, 0, c });
		}
		// a -> c
		if (visited[0][b] != 1) q.push({ 0, b, a + c });
	
		// c -> a
		if (a + c > A) {
			if (visited[A][b] != 1) q.push({ A, b, a + c - A });
		}
		else {
			if (visited[a + c][b] != 1) q.push({c + a, b, 0 });
		}
		// b -> c
		if (visited[a][0] != 1) q.push({ a, 0, b + c });
		
		// c -> b
		if (c + b > B) {
			if (visited[a][B] != 1) q.push({ a, B, b + c - B });
		}
		else {
			if (visited[a][c + b] != 1) q.push({ a, b + c, 0 });
		}
	}
	
}

int main() {
	cin >> A >> B >> C;
	bfs(0, 0, C);
	for (int i = 0; i < 201; i++) {
		if (result[i] == 1) {
			cout << i << " ";
		}
	}
}