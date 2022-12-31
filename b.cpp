//
// Created by longdnk on 12/25/2022.
//
#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<pair<int, int>> ls;
    list<pair<int, int>> list;
    auto solve = [&](string s) {
        int fi, se;
        string res, rev;
        int length = (int) s.size();
        switch (length) {
            case 1:
                fi = stoi(s), se = stoi(s);
                break;
            case 2:
                fi = s[0] - '0', se = s[length - 1] - '0';
                break;
            case 3:
                --length;
                for (int i = 0; i < length; ++i) {
                    res.push_back(s[i]);
                }
                ++length;
                rev.push_back(s[length - 1]);
                fi = stoi(res), se = stoi(rev);
                break;
            case 4:
                int tmp = length;
                tmp >>= 1;
                for (int i = 0; i < tmp; ++i) {
                    res.push_back(s[i]);
                }
                for (int i = tmp; s[i] != '\0'; ++i) {
                    rev.push_back(s[i]);
                }
                fi = stoi(res), se = stoi(rev);
                break;
        }
        ls.emplace_back(fi, se);
        list.emplace_back(fi, se);
    };
//    int n;
//    cin >> n;
//    string a[n + 1];
//    for (int i = 1; i <= n; ++i) {
//        cin >> a[i];
//        solve(a[i]);
//    }
    string s;
    cin >> s;
    solve(s);
//    for voi vector
//    for (auto [key, value]: ls) {
//        cout << key << ' ' << value << '\n';
//    }

//   for voi list
    for (auto item: list) {
        cout << item.first << ' ' << item.second << '\n';
    }

}
// 9
// 28 27 35 33 29 36 72 108 109
