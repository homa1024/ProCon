
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FORCLS(i,a,b) for(int i = (a); i <= (b); i++)
#define REPCLS(i,n) FORCLS(i,1,n)

using Int = long;
Int dp[301][301][301];
vector<pair<int,int>> rtolxs[300];

int n, m;
Int mod = 10000007;

bool checkRule(int a, int b, int c, int r) {
    int l, x;
    int ls[] = {a,b,c};
    sort(ls, ls+3);
    for (auto p : rtolxs[r]) {
        tie(l,x) = p;
        bool out = true;
        switch(x) {
            case 1:
                out = (l <= ls[0] || l <= ls[1]);
                break;
            case 2:
                out = (l <= ls[0] || ls[1] < l);
                break;
            case 3:
                out = (ls[0] < l || ls[1] < l);
                break;
        }
        if (out)
            return false;
    }
    return true;
}
void update(int r, int g, int b, int k, Int v) {
    if (dp[r][g][b] != -1 && checkRule(r, g, b, k)) {
        dp[r][g][b] += v;
        dp[r][g][b] %= mod;
    }
    else {
        dp[r][g][b] = -1;
    }
}
void solve() {
    cin >> n >> m;
    REP(i, m) {
        int l,r,x;
        cin >> l >> r >> x;
        rtolxs[r].push_back(make_pair(l,x));
    }
    dp[0][0][0] = 1;
    Int result = 0;
    REP(r, n + 1) REP(g, n + 1) REP(b, n + 1) {
        if (dp[r][g][b] <= 0)
            continue;
        int k = max({r,g,b}) + 1;
        if (k == n + 1) {
            result += dp[r][g][b];
            result %= mod;
        }
        else {
            update(k, g, b, k, dp[r][g][b]);
            update(r, k, b, k, dp[r][g][b]);
            update(r, g, k, k, dp[r][g][b]);
        }
    }
    
    cout << result << endl;
}

#ifdef DEBUG
#define MAIN hoge
#else
#define MAIN main
#endif

int MAIN() {
    solve();
    
    return 0;
}
