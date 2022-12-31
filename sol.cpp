//
// Created by longdnk on 12/16/22.
//
#include "bits/stdc++.h"

using namespace std;
const int maxn = 1e6 + 9;
bitset<maxn> isPrime;
vector<int> prime;
vector<int64_t> p;
int t, u, v;
int64_t x, y;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    isPrime[2] = true;
    prime.assign(1, 2);

    int sqrtn = (int) sqrt(1e6);
    for (int i = 3; i <= 1e6; i += 2) {
        isPrime.set(i);
    }
    for (int i = 3; i <= 1e6; i += 2) {
        if (isPrime[i]) {
            prime.emplace_back(i);
            if (i > sqrtn) {
                continue;
            }
            for (int j = i * i; j <= 1e6; j += i << 1) {
                isPrime.reset(j);
            }
        }
    }

    for (auto item: prime) {
        if (item != 3) {
            p.emplace_back(1LL * item * item * 9);
        }
    }

    auto findFi = [&](int64_t x) -> int {
        int l = 0, r = (int) p.size(), mid, res = -1;
        while (l <= r) {
            mid = (r + l) >> 1;
            if (p[mid] <= x) {
                res = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return res;
    };
    auto findSe = [&](int64_t x) -> int {
        int l = 0, r = (int) p.size(), mid, res = -1;
        while (l <= r) {
            mid = (r + l) >> 1;
            if (p[mid] >= x) {
                res = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return res;
    };

    cin >> t;
    while (t--) {
        cin >> x >> y;
        u = findSe(x), v = findFi(y);
        cout << v - u + 1 << '\n';
    }
}