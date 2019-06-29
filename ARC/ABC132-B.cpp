
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

const int N_MAX = 20;

int n;
int p[N_MAX] = {};
void solve() {
    cin >> n;
    REP(i,n) { cin >> p[i];}
    int cnt = 0;
    REP (i, n-2) {
        bool cnd1 = p[i] < p[i+1] && p[i+1] < p[i+2];
        bool cnd2 = p[i] > p[i+1] && p[i+1] > p[i+2];
        if (cnd1 || cnd2) {
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    solve();
    
    return 0;
}
