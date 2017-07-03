// 10:40

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

#if defined(DEBUG) && true
#define DOUT(x) {cout << #x << ":" << x << endl;}
#define DOUTA(ary,n) {cout << #ary << ": "; for(int i = 0; i < (n); i++) { cout << (ary)[i] << ", ";} cout << endl; }
#else
#define DOUT(x)
#define DOUTA(ary,n)
#endif

using Int = long;

const Int N_MAX = 100003;
Int n,m;
Int as[N_MAX];
Int bs[N_MAX * 2];
Int cs[N_MAX * 2];

void solve() {
    Int sum = 0;
    cin >> n >> m;
    REP(i, n) { cin >> as[i]; as[i]--;}
    REP(i, 2*m) { bs[i] = 0; }
    REP(i, n-1) {
        Int s = as[i];
        Int t = as[i + 1];
        t = (s < t) ? t : t + m;
        bs[s + 2] += 1;
        bs[t + 1] -= 1;
        cs[t + 1] -= t - s - 1;
        sum += t - s;
    }
    REP(i, 2*m-1) {
        bs[i + 1] += bs[i];
    }
    REP(i, 2*m-1){
        bs[i+1] += bs[i] + cs[i+1];
    }
    DOUTA(bs, 2*m);
    REP(i, m) {
        bs[i] += bs[i + m];
    }
    DOUTA(bs, m);
    cout << sum - *max_element(bs, bs + m) << endl;
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
