
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); (i)++)
#define REP(i,n) FOR((i),0,(n))
#define FORCLS(i,a,b) for(int (i) = (a); i <= (b); (i)++)
#define REPCLS(i,n) FORCLS((i),1,(n))

using Int = long long;
const Int mod = 1000000007ll;

Int fact(Int n) {
    Int ret = 1;
    for (Int i = 1; i <= n; i++){
        ret *= i;
        ret %= mod;
    }
    return ret;
}
void solve() {
    Int n, m;
    Int ans = 0;
    cin >> n >> m ;
    Int d = abs(n - m);
    switch (d) {
        case 0:
            ans = fact(n) * fact(m);
            ans %= mod;
            ans *= 2;
            ans %= mod;
            break;
        case 1:
            ans = fact(n) * fact(m);
            ans %= mod;
            break;
        default:
            ans = 0;
            break;
    }
    cout << ans << endl;
}
void solve() {
    Int n,m;
    
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
