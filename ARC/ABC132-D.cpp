
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
template<typename T>
T extGcdRec(T r1, T r2, T x1, T x2, T y1, T y2, T &x, T &y) {
    if (r2 == 0) {
        x = x1; y = y1;
        return r1;
    }
    T r3 = r1 / r2;
    return extGcdRec(r2, r1 % r2, x2, x1 - r3 * x2, y2, y1 - r3 * y2, x, y);
}
template<typename T>
T extGcd(T a, T b, T &x, T &y) {
    if (a < b) return extGcd(b, a, y, x);
    return extGcdRec<T>(a, b, 1, 0, 0, 1, x, y);
}
template<typename T>
T invMod(T a, T m){ // Zm上乗法逆数
    T x, y;
    if (extGcd<T>(a, m, x, y) == 1) return (x + m) % m;
    return 0;
}


const int N_MAX = 2001;
int N;
int K;
int numB, numR;
long invM[N_MAX] = {};
long nCr[N_MAX][N_MAX] = {};
const long MOD = 1000000000 + 7;

void init() {
    // invM
    REP(n, N_MAX) {
        invM[n] = invMod<long>(n, MOD);
    }
    // nCr
    REP(n, N_MAX) {
        nCr[n][0] = 1;
    }
    REP(r, N_MAX) {
        nCr[0][r] = 1;
    }
    FOR(r, 1, N_MAX) {
        FOR(n, r, N_MAX) {
            nCr[n][r] = (((n * invM[r]) % MOD) * nCr[n-1][r-1]) % MOD;
        }
    }
}

inline long sub(int sectionNumB, int sectionNumR) {
    // n(num) を s(section)個の自然数に分ける分け方の個数は (n-1)C(s-1)
    if (sectionNumB == 0 || sectionNumR == 0) return 0;
    return (nCr[numB-1][sectionNumB-1] * nCr[numR-1][sectionNumR-1]) % MOD;
}
void solve() {
    cin >> N >> K;
    numB = K;
    numR = N-K;

    init();
    
    if (numR == 0) { // 赤がないパタン
        cout << 1 << endl;
        FOR(i, 2, K+1) {
            cout << 0 << endl;
        }
        return;
    }
    
    FOR(i, 1, K+1) {
        long res = 0;
        const int sectionNumB = i;
        for (int sectionNumR : {i-1, i, i, i+1} /* B-B, B-R, R-B, R-R */) {
            res = (res + sub(sectionNumB, sectionNumR)) % MOD;
        }
        cout << res << endl;
    }
}

int main() {
    solve();
    
    return 0;
}
