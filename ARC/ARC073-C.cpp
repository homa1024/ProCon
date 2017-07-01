
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <vector>
#include <limits>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FORCLS(i,a,b) for(int i = (a); i <= (b); i++)
#define REPCLS(i,n) FORCLS(i,1,n)

using Int = long;
const int N_MAX = 200005;
Int xy[2*N_MAX];
int n;

// case min = R, max = B
Int calcOptValue1(Int minElm, Int maxElm) {
    Int rMin = minElm;
    Int bMax = maxElm;
    Int rMax = rMin;
    Int bMin = bMax;
    REP(i, n) {
        Int l = xy[2*i], h = xy[2*i + 1];
        if (l > h) swap(l,h);
        if (rMax < l) rMax = l;
        if (h < bMin) bMin = h;
    }
    return (rMax - rMin) * (bMax - bMin);
}

// case min = R, max = R
Int calcOptValue2(Int minElm, Int maxElm) {
    int minCnt = 0;
    int maxCnt = 0;
    Int bMin = maxElm;
    Int bMax = minElm;
    vector<pair<Int,Int>> v;
    
    REP(i, n) {
        Int l = xy[2*i], h = xy[2*i + 1];
        if (l > h) swap(l,h);
        v.push_back(make_pair(l,h));
        if (h == minElm) minCnt++;
        if (h == maxElm) maxCnt++;
        if (l < bMin) bMin = l;
        if (bMax < l) bMax = l;
    }
    sort(&v[0], &v[n]);
    Int bDiff = numeric_limits<Int>::max();
    Int swapedBMin = maxElm;
    REP(i, n){
        bMin = v[i].first;
        if (swapedBMin < bMin) {
            if (minCnt > 0 && maxCnt > 0) {
                bDiff = min(bDiff, bMax - swapedBMin);
            }
            break;
        }
        if (minCnt > 0 && maxCnt > 0){
            bDiff = min(bDiff, bMax - bMin);
        }
        /* swap i */ {
            bMax = max(bMax, v[i].second);
            swapedBMin = min(swapedBMin, v[i].second);
            if (v[i].first == minElm) minCnt++;
            if (v[i].first == maxElm) maxCnt++;
            if (v[i].second == minElm) minCnt--;
            if (v[i].second == maxElm) maxCnt--;
        }
    }
    if (bDiff == numeric_limits<Int>::max()) return bDiff;
    return (maxElm - minElm) * bDiff;
}
void solve() {
    cin >> n;
    if (n == 1){
        cout << 0 << endl;
        return;
    }
    REP(i, 2*n) cin >> xy[i];
    Int minElm = *min_element(xy, xy + (2*n));
    Int maxElm = *max_element(xy, xy + (2*n));
    
    cout << min(calcOptValue1(minElm, maxElm), calcOptValue2(minElm, maxElm)) << endl;
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
