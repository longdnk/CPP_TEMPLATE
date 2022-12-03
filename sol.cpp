//
// Created by longsiga on 12/3/22.
//
#include "bits/stdc++.h"

using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ul unsigned long
#define ld long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define FORUP(i, star, end) for (int i = star; i <= end; ++i)
#define FORDOWN(i, star, end) for (int i = star; i >= end; --i)
#define FORAUTO(item, m) for (auto item : m)
#define foreach(vector) for (auto it : vector) cout << it << ' ';
#define Map_Foreach(map) for (auto it : map) cout << it.fi << ' ' << it.se << "\n";
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rev(i, n) for (ll i = n - 1; i >= 0; --i)
#define AutoInputArray(a, b, x) FORUP(a, 1, b) cin >> x[i];
#define AutoInputArrayFr0(a, b, x) rep(0, n) cin >> x[i];
#define whatis(x) cout << "Line " << __LINE__ << ": " << #x << " = " << (x) << ", ";
#define ShowTime() cerr << "Durex Executed in " << clock() * 1000 / CLOCKS_PER_SEC << " ms";
#define UpCase(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
#define LowCase(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(x) (int)x.size()
#define endl '\n'
#define elif else if

inline void debug_out() { cerr << endl; }

inline void in() { }

inline void out() { }

inline void read() { }
// windows version :v
// inline int getchar_unlocked() { return _getchar_nolock(); }
// inline int putchar_unlocked(char c) { return _putchar_nolock(c); }

template<typename Head, typename... Tail>
inline void debug_out(Head H, Tail... T) {
    cerr << " " << H << ",";
    debug_out(T...);
}

template<typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << p.first << " " << p.second << endl; }

template<typename a, typename b, typename c>
ostream &operator<<(ostream &os, const pair<a, pair<b, c>> &p) { return os << p.second.first << ' ' << p.second.second; }

template<typename T>
inline void inp(T &x) {
    x = 0;
    bool neg = 0;
    T c = getchar_unlocked();
    if (c == '-') neg = 1, c = getchar_unlocked();
    while ((c < 48) || (c > 57)) c = getchar_unlocked();
    for (; c < 48 or c > 57; c = getchar_unlocked());
    for (; c > 47 && c < 58; c = getchar_unlocked()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x *= -1;
}

template<typename T>
inline void outp(T n) {
    bool neg = 0;
    if (n < 0) n *= -1, neg = 1;
    char snum[100009];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    --i;
    if (neg) putchar_unlocked('-');
    while (i >= 0) putchar_unlocked(snum[i--]);
    putchar_unlocked(' ');
}

template<typename T, typename... Args>
inline void in(T &num, Args &... args) {
    inp(num);
    in(args...);
}

template<typename T, typename... Args>
inline void out(T first, Args... args) {
    outp(first);
    out(args...);
}

//template <typename T> inline void out(T fi) { cout << fi; putchar_unlocked(endl); }
template<class T>
inline void readln(T &x) {
    static char ch;
    static bool neg;
    for (ch = neg = 0; ch < '0' || '9' < ch; neg |= ch == '-', ch = getchar_unlocked());
    for (x = 0; '0' <= ch && ch <= '9'; (x *= 10) += ch - '0', ch = getchar_unlocked());
    x = neg ? -x : x;
}

template<class T, typename... Args>
inline void read(T &num, Args &... args) { readln(num), read(args...); }

#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", debug_out(__VA_ARGS__)
using namespace std;

const int maxn = 1e9 + 1e8 + 1, nmax = 1e3 + 9;

typedef struct edge {
    int u, v, c;

    inline edge() : u(0), v(0), c(0) { };

    inline edge(int u, int v, int c) : u(u), v(v), c(c) { };
} edge;

struct comp {
public:
    inline bool operator()(edge a, edge b) { return a.c < b.c; }
} comp;

class disjotinset {
private:
    int n;
    vector<int> parent;

public:
    inline disjotinset() : n(nmax), parent(vector<int>(nmax, -1)) { }

    inline disjotinset(int n) : n(n), parent(vector<int>(n + 1, -1)) { }

    inline int root(int u) {
        if (parent[u] < 0) {
            return u;
        }
        return (parent[u] = root(parent[u]));
    }

    inline bool conn(int u, int v) { return root(u) == root(v); }

    inline void unionn(int u, int v) {
        int root_u = root(u), root_v = root(v);
        if (root_u == root_v)
            return;
        if (parent[root_u] < parent[root_v]) {
            swap(root_u, root_v);
        }
        parent[root_v] += parent[root_u];
        parent[root_u] = root_v;
    }
};

int n, m, t, s { 1 };

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read(n, m);
    t = n;
    vector<edge> e;
    for (int i = 1, u, v, c; i <= m; ++i) {
        read(u, v, c);
        e.emplace_back(edge(u, v, c));
    }
    sort(all(e), comp);
    disjotinset ds(n);
    if (s == t) {
        putchar_unlocked('0');
        putchar_unlocked('\n');
        ShowTime();
        exit(0);
    }
    for (int i = 0; i < m; ++i) {
        ds.unionn(e[i].u, e[i].v);
        if (ds.conn(s, t)) {
            out(e[i].c);
            putchar_unlocked('\n');
            ShowTime();
            exit(0);
        }
    }
}