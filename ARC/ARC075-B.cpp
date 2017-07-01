
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FORCLS(i,a,b) for(int i = (a); i <= (b); i++)
#define REPCLS(i,n) FORCLS(i,1,n)

using Int = long;

const Int n_max = 100004;
Int n,a,b;
Int h[n_max];

bool check(Int cnt) {
    Int c = 0;
    REP(i, n) {
        Int v = h[i] - cnt*b;
        if (v <= 0) return true;;
        Int q = v / (a - b);
        Int r = v % (a - b);
        q = q + (r == 0 ? 0 : 1);
        c += q;
        if (cnt < c) return false;
    }
    return true;
}
void solve() {
    cin >> n >> a>> b;
    REP(i,n) { cin >> h[i];}
    sort(h, h + n, [](Int a, Int b) { return a > b; });
    h[n] = 0;
    
    Int l = 0;
    Int r = 1000000001;
    while (r - l > 1) {
        Int mid = (r + l) / 2;
        
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r << endl;
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
