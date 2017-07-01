
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

using Int = long;

void solve() {
    Int a[3];
    for(auto& v : a) {
        cin >> v;
    }
    for(auto v : a) {
        cout << v << ",";
    }
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
