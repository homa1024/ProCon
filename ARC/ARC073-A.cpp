
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FORCLS(i,a,b) for(int i = (a); i <= (b); i++)
#define REPCLS(i,n) FORCLS(i,1,n)

using Int = long;
int N, T;

void solve() {
    Int t0, t1;
    Int sumTime = 0;
    cin >> N >> T;
    t0 = -T - 1;
    REP(i, N){
        cin >> t1;
        if (t1 - t0 >= T){
            sumTime += T;
        } else {
            sumTime += t1 - t0;
        }
        t0 = t1;
    }
    cout << sumTime << endl;
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
