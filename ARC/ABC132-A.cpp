
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <vector>
#include <limits>
#include <string>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FORCLS(i,a,b) for(int i = (a); i <= (b); i++)
#define REPCLS(i,n) FORCLS(i,1,n)


void solve() {
    string s;
    cin >> s;
    int ch['Z' - 'A'] = {};
    FOR(i, 0, 4) {
        ch[s[i] - 'A']++;
    };
    int fifty = 0;
    for(int cnt : ch) {
        if (cnt == 2) {
            fifty++;
        }
    }
    cout << (fifty == 2 ? "Yes" : "No") << endl;

}

int main() {
    solve();
    
    return 0;
}
