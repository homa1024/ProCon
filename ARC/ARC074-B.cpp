
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
#include <set>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FORCLS(i,a,b) for(int i = (a); i <= (b); i++)
#define REPCLS(i,n) FORCLS(i,1,n)

using Int = long long;
const Int N_MAX = 100002;
Int as[3 * N_MAX];
Int n;


void solve() {
    cin >> n;
    REP(i, 3*n) cin >> as[i];
    priority_queue<Int, vector<Int>, greater<Int>> s1;
    set<pair<Int,Int>> s2;
    set<pair<Int,Int>> remain;
    Int sum1 = 0, sum2 = 0;
    Int bestScore;
    for(int i = 0; i < n; i++) {
        s1.push(as[i]);
        sum1 += as[i];
    }
    for(Int i = n; i < 3*n; i++) {
        remain.insert({as[i], i});
    }
    REP(i, n){
        auto x = *remain.begin();
        remain.erase(remain.begin());
        s2.insert(x);
        sum2 += x.first;
    }
    bestScore = sum1 - sum2;
    for (Int i = n; i < 2*n; i++){
        {
            Int x = s1.top();
            if (x < as[i]) {
                s1.pop();
                s1.push(as[i]);
                sum1 += as[i] - x;
            }
        }
        {
            auto p = make_pair(as[i], i);
            auto ite = remain.find(p);
            if (ite != remain.end()) {
                remain.erase(ite);
            }
            else {
                s2.erase(p);
                auto x = *remain.begin();
                remain.erase(remain.begin());
                s2.insert(x);
                sum2 += x.first - as[i];
            }
            Int scr = sum1 - sum2;
            bestScore = max(bestScore, scr);
        }
    }
    
    cout << bestScore << endl;
    return;
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
