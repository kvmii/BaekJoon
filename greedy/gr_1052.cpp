#include <iostream>

using namespace std;
int n, k;

int bottle(int n) {
    int cnt = 0;
    while (n > 0) {
        if (n % 2 == 1) cnt++;
        // 나눠지지 않으면
        n /= 2;
    }
    return cnt;
}

int main() {
    cin >> n >> k;
    int ans = 0;
    while (1) {
        if (bottle(n) <= k) break;
        // 최대한 나눴을 때 k보다 작으면
        else {
            ans++;
            n++;
            // 병 개수 증가
        }
    }
    cout << ans << endl;
}
