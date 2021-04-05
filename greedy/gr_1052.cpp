#include <iostream>

using namespace std;
int n, k;

int bottle(int n) {
    int cnt = 0;
    while (n > 0) {
        if (n % 2 == 1) cnt++;
        // �������� ������
        n /= 2;
    }
    return cnt;
}

int main() {
    cin >> n >> k;
    int ans = 0;
    while (1) {
        if (bottle(n) <= k) break;
        // �ִ��� ������ �� k���� ������
        else {
            ans++;
            n++;
            // �� ���� ����
        }
    }
    cout << ans << endl;
}
