
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

const int N_MAX = 100005;
int n;
int d[N_MAX] = {};

void solve() {
    cin >> n;
    REP(i,n) { cin >> d[i];}
    
    if (n % 2 == 1) {
        cout << "0" << endl;
        return;
    }
    // n % 2 == 0
    sort(d, d + n);
    int l = d[n/2 - 1];
    int r = d[n/2];
    cout << r - l << endl;
}

int main() {
    solve();
    
    return 0;
}
