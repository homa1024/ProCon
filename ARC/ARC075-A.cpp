
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FORCLS(i,a,b) for(int i = (a); i <= (b); i++)
#define REPCLS(i,n) FORCLS(i,1,n)

using Int = long;
Int s[103];
void solve() {
    Int n;
    cin >> n;

    REP(i, n) {
        cin >> s[i];
    }
    Int sum = 0;
    REP(i,n){sum += s[i];}
    if (sum % 10 != 0){
        cout << sum << endl;
        return;
    }
    
    Int v = sum;
    REP(i, n){
        if (s[i] < v && s[i] % 10 != 0) {
            v = s[i];
        }
    }
    cout << sum - v << endl;
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
