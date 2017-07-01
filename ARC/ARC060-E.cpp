
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FORCLS(i,a,b) for(int i = (a); i <= (b); i++)
#define REPCLS(i,n) FORCLS(i,1,n)

using Int = long;

const int N_MAX = 100005;
const int LOG_N_MAX = 17;
const Int L_MAX = 1000000005;

Int xs[N_MAX];
int dbl[LOG_N_MAX + 1][N_MAX];

int getDay(int a, const int b){
    int day = 0;
    while (a < b) {
        int i = 0;
        while (dbl[i + 1][a] < b) i++;
        a = dbl[i][a];
        day += (1 << i);
    }
    return day;
}
void solve() {
    int N, Q;
    Int L;
    cin >> N;
    REP(i, N) cin >> xs[i];
    xs[N] = L_MAX;
    cin >> L;
    {
        int i = 0,j = 0;
        while(j < N) {
            while(xs[j + 1] - xs[i] <= L) j++;
            dbl[0][i] = j;
            i++;
        }
    }
    for (int s = 1; (1 << s) <= N; s++){
        REP(i, N){
            dbl[s][i] = dbl[s-1][dbl[s-1][i]];
        }
    }
    
    cin >> Q;
    REP(q, Q){
        int a,b;
        cin >> a >> b;
        if (a > b) swap(a,b);
        cout << getDay(a - 1,b - 1) << endl;
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
