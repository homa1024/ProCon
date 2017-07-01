
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); (i)++)
#define REP(i,n) FOR((i),0,(n))
#define FORCLS(i,a,b) for(int (i) = (a); i <= (b); (i)++)
#define REPCLS(i,n) FORCLS((i),1,(n))

using Int = long;
Int R,C,N;

Int getPos(Int x, Int y){
    if (x == 0) {
        return y;
    } else if (y == C) {
        return C + x;
    } else if (x == R) {
        return C + R + (C - y);
    } else if (y == 0) {
        return C + R + C + (R - x);
    } else {
        return -1;
    }
}

void solve() {
    cin >> R >> C >> N;
    vector<pair<Int,Int>> pos_inxs;
    REP(i, N){
        Int x0,y0, x1,y1;
        cin >> x0 >> y0 >> x1 >> y1;
        Int p0 = getPos(x0, y0);
        Int p1 = getPos(x1,y1);
        if (p0 >= 0 && p1 >= 0) {
            pos_inxs.push_back(make_pair(p0, i)); // (時計回りpos, index)
            pos_inxs.push_back(make_pair(p1, i));
        }
    }
    Int size = pos_inxs.size();
    if (size <= 1) {
        cout << "YES" << endl;
        return;
    }
    sort(&pos_inxs[0], &pos_inxs[0] + size);
    stack<Int> s;
    for (Int i = 0 ; i < size; i++){
        Int ix = pos_inxs[i].second;
        if (s.empty() || s.top() != ix){
            s.push(ix);
        } else {
            s.pop();
        }
    }
    cout << (s.empty() ? "YES" : "NO") << endl;
    
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
