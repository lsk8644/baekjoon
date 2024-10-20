#include <iostream>
#include <algorithm>
#include <vector>
using ll = long long;
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll N, M, ans = 0; cin >> N >> M;
    ll H[N];
    for (int i = 0; i < N; i++) cin >> H[i];
    sort(H, H + N);
    ll low = 0, high = H[N - 1], mid = 0, chk = 1e9;
    while (low <= high) {
        mid = (low + high +1) / 2; ll sum = 0;
        for (int i = 0; i < N; i++) if (H[i] > mid) sum += H[i] - mid;
            if (sum >= M) {if (low == mid) break; low = mid;}
            else high = mid - 1;
    }
    cout << mid;
}
