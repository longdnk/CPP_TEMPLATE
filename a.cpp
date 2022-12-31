//
// Created by longdnk on 12/20/2022.
//
#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m, n, sum {};
    cin >> m >> n;
    int a[m + 1][n + 1];
    memset(a, 0x0, sizeof(a));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            sum += a[i][j];
        }
        cout << sum << '\n';
        sum = { 0 };
    }
}