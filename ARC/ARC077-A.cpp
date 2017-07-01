
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
const int N_MAX = 200003;
Int as[N_MAX];
int n;
void solve() {
    cin >> n;
    REP(i, n) { cin >> as[i]; }
    deque<Int> q;
    int i = 0;
    if (n % 2 == 1){
        q.push_front(as[i]);
        i++;
    }
    while (i < n){
        q.push_back(as[i]);
        i++;
        q.push_front(as[i]);
        i++;
    }
    for(auto x : q) {
        cout << x << " ";
    }
    cout << endl;
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
