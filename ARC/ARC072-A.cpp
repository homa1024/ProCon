
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FORCLS(i,a,b) for(int i = (a); i <= (b); i++)
#define REPCLS(i,n) FORCLS(i,1,n)


using Int = long long;
Int cnt[2];
int sign[2];
Int v[2];
int n;
Int a;

void solve() {
    REP(i, 2) cnt[i] = 0;
    REP(i, 2) v[i] = 0;
    sign[0] = 1;
    sign[1] = -1;
    cin >> n;
    REP(i, n) {
        cin >> a;
        REP(j, 2){
            v[j] += a;
            if (sign[j] == 1 && v[j] < 1){
                cnt[j] += -v[j] + 1;
                v[j] = 1;
            }
            if (sign[j] == -1 && v[j] > -1) {
                cnt[j] += v[j] + 1;
                v[j] = -1;
            }
            sign[j] *= -1;
        }
    }
    cout << (cnt[0] < cnt[1] ? cnt[0] : cnt[1]) << endl;
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
