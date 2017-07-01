
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FORCLS(i,a,b) for(int i = (a); i <= (b); i++)
#define REPCLS(i,n) FORCLS(i,1,n)

using Int = long long;

void solve() {
    Int a,b;
    cin >> a >> b;
    cout << ((abs(a-b) > 1) ? "Alice" : "Brown") << endl;
    Int minV = min
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
