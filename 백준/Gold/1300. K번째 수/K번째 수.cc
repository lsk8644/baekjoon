#include <iostream>
#include <algorithm>
#include <vector>
using ll = long long;
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll N, K, ans = 0; cin >> N >> K;
    ll start = 1, end = K;
    while (start <= end) {
        ll mid = start + (end - start) / 2, cnt = 0;
        for (int i = 1; i <= N; i++) cnt += min(mid / i, N);
        if (cnt < K) start = mid + 1;
        else { end = mid - 1; ans = mid; }
    }
    cout << ans;
}
