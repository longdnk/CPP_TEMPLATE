//
// Created by longsiga on 12/3/22.
//
#include "bits/stdc++.h"

#define ll long long int
using namespace std;

char cp;
bool b[6][11];
stack<int> q;
int cost[11][11][11][11][11], s;
ll dp[11][11][11][11][11][11][2], answer;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 10; ++j) {
            cin >> cp;
            b[i][j] = cp == '1';
        }
    }
    int c[6], l[6], r[6];
    for (c[1] = 0; c[1] <= 10; ++c[1]) {
        for (c[2] = 0; c[2] <= 10; ++c[2]) {
            for (c[3] = 0; c[3] <= 10; ++c[3]) {
                for (c[4] = 0; c[4] <= 10; ++c[4]) {
                    for (c[5] = 0; c[5] <= 10; ++c[5]) {
                        for (int i = 1; i < 6; ++i) {
                            while (!q.empty() && c[q.top()] >= c[i]) {
                                q.pop();
                            }
                            if (q.empty()) {
                                l[i] = 0;
                            } else {
                                l[i] = q.top();
                            }
                            q.push(i);
                        }
                        while (!q.empty()) {
                            q.pop();
                        }
                        for (int i = 5; i; --i) {
                            while (!q.empty() && c[q.top()] >= c[i]) {
                                q.pop();
                            }
                            if (q.empty()) {
                                r[i] = 5;
                            } else {
                                r[i] = q.top() - 1;
                            }
                            q.push(i);
                        }
                        while (!q.empty()) {
                            q.pop();
                        }
                        for (int i = 1; i <= 5; ++i) {
                            cost[c[1]][c[2]][c[3]][c[4]][c[5]] = max(cost[c[1]][c[2]][c[3]][c[4]][c[5]], (r[i] - l[i]) * c[i]);
                        }
                    }
                }
            }
        }
    }
    dp[0][0][0][0][0][0][0] = 1;
    for (int i = 0; i < 10; ++i) {
        for (c[1] = 0; c[1] <= i; ++c[1]) {
            for (c[2] = 0; c[2] <= i; ++c[2]) {
                for (c[3] = 0; c[3] <= i; ++c[3]) {
                    for (c[4] = 0; c[4] <= i; ++c[4]) {
                        for (c[5] = 0; c[5] <= i; ++c[5]) {
                            for (int c1 = b[1][i + 1], d1 = c1 ? 0 : c[1] + 1; c1 < 2; ++c1, d1 = 0) {
                                for (int c2 = b[2][i + 1], d2 = c2 ? 0 : c[2] + 1; c2 < 2; ++c2, d2 = 0) {
                                    for (int c3 = b[3][i + 1], d3 = c3 ? 0 : c[3] + 1; c3 < 2; ++c3, d3 = 0) {
                                        for (int c4 = b[4][i + 1], d4 = c4 ? 0 : c[4] + 1; c4 < 2; ++c4, d4 = 0) {
                                            for (int c5 = b[5][i + 1], d5 = c5 ? 0 : c[5] + 1; c5 < 2; ++c5, d5 = 0) {
                                                if (cost[d1][d2][d3][d4][d5] > s) continue;
                                                dp[i + 1][d1][d2][d3][d4][d5][cost[d1][d2][d3][d4][d5] == s] += dp[i][c[1]][c[2]][c[3]][c[4]][c[5]][0];
                                                dp[i + 1][d1][d2][d3][d4][d5][1] += dp[i][c[1]][c[2]][c[3]][c[4]][c[5]][1];
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (c[1] = 0; c[1] <= 10; ++c[1]) {
        for (c[2] = 0; c[2] <= 10; ++c[2]) {
            for (c[3] = 0; c[3] <= 10; ++c[3]) {
                for (c[4] = 0; c[4] <= 10; ++c[4]) {
                    for (c[5] = 0; c[5] <= 10; ++c[5]) {
                        answer += dp[10][c[1]][c[2]][c[3]][c[4]][c[5]][1];
                    }
                }
            }
        }
    }
    cout << answer << '\n';
}