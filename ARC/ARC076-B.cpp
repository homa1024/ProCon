
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <tuple>


using namespace std;

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); (i)++)
#define REP(i,n) FOR((i),0,(n))
#define FORCLS(i,a,b) for(int (i) = (a); i <= (b); (i)++)
#define REPCLS(i,n) FORCLS((i),1,(n))

using Int = long;
const int N_MAX = 100003;
Int uf_city[N_MAX]; // union find;

Int root(Int i) {
    if (uf_city[i] == i) return i;
    return uf_city[i] = root(uf_city[i]);
}
void join(Int i, Int j){
    uf_city[root(j)] = root(i);
}

bool isSame(Int i, Int j){
    return root(i) == root(j);
}

Int n;
tuple<Int, Int, Int> xys[N_MAX];
tuple<Int, Int, Int> yxs[N_MAX];

void solve() {
    cin >> n;
    REP(i, n){
        Int x,y;
        cin >> x >> y;
        xys[i] = make_tuple(x,y,i);
        yxs[i] = make_tuple(y,x,i);
    }
    sort(xys, xys + n);
    sort(yxs, yxs + n);
    priority_queue<tuple<Int,Int,Int>,vector<tuple<Int,Int,Int>>, greater<tuple<Int,Int,Int>>> q;
    
    REP(i, n-1){
        Int x0,y0,i0;
        Int x1, y1, i1;
        Int d;
        tie(x0,y0,i0) = xys[i];
        tie(x1,y1,i1) = xys[i + 1];
        d = min(x1 - x0, abs(y1 - y0));
        q.push(make_tuple(d, i0, i1));
        
        tie(y0,x0,i0) = yxs[i];
        tie(y1,x1,i1) = yxs[i + 1];
        d = min(abs(x1 - x0), y1 - y0);
        q.push(make_tuple(d, i0, i1));
    }
    REP(i, n){
        uf_city[i] = i;
    }
    Int money = 0;
    while (!q.empty()) {
        Int d,i,j;
        tie(d,i,j) = q.top(); q.pop();
        if (!isSame(i, j)) {
            money += d;
            //cout << "join" << i << j << endl;
            join(i, j);
        }
//        REP(k ,n){
//            cout << k << ":" << uf_city[k] << ", ";
//        }
//        cout << endl;
    }
    cout << money << endl;
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
