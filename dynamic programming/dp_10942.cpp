#include <iostream>

using namespace std;

int arr[2001];
bool pnd[2001][2001];
int N, M;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			pnd[i][j] = true;
		}
	}

	for (int i = N; i > 0; i--) {
		for (int j = i; j <= N; j++) {
			if (i == j)
				pnd[i][j] = true;
			else {
				if (arr[i] == arr[j]) {
					if (j - i == 1)
						pnd[i][j] = true;
					else if (pnd[i + 1][j - 1])
						pnd[i][j] = true;
					// pnd[i+1][j-1]이 true고 arr[i] == arr[j] 면 pnd[i][j]도 true
					else
						pnd[i][j] = false;
				}
				else
					pnd[i][j] = false;
			}
		}

	}

	scanf("%d", &M);
	for (int j = 0; j < M; j++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", pnd[a][b]);
	}

	// cin, cout을 썼을 때 시간초과가 생겨서 scanf, printf를 사용
	system("PAUSE");
}