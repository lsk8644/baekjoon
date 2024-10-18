#include<iostream>
#define MOD 15746
using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    int dp[N];
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < N; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
        dp[i] %= MOD;
    }
    cout << dp[N - 1];
}