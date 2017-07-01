// ARC059E
// 20160924-1321-1630

//mod‚Ìˆø‚«Z‚Í”‚Ì‘å¬‚Ì‘O’ñ‚ªˆÙ‚È‚é‚Æ‚«‚ ‚èB‚¿‚á‚ñ‚Æ+mod %mod‚·‚é

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <array>
#include <cmath>
#include <limits>

using namespace std;

using IntType = long long;

const int CHILD_MAX = 401;
const int CANDY_MAX = 401;
const int HASYAGI_MAX = 401;
int childNum;
int candyNum;
int hasyagis[2][CHILD_MAX];
const IntType mod = 1000000007;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i = (a); i < (b); i++)

IntType powAccumSum[CANDY_MAX][HASYAGI_MAX];
void calcPowAccumSum() {
	REP(i, HASYAGI_MAX) {
		powAccumSum[0][i] = 1;
	}
	powAccumSum[0][0] = 0;
	FOR(a, 1, CANDY_MAX) { // calc i^a
		REP(i, HASYAGI_MAX) {
			powAccumSum[a][i] = (powAccumSum[a - 1][i] * i) % mod;
		}
	}
	REP(a, CANDY_MAX) { // calc sum_i i^a
		FOR(i, 1, HASYAGI_MAX) {
			powAccumSum[a][i] += powAccumSum[a][i - 1];
			powAccumSum[a][i] %= mod;
		}
	}
}
IntType polyDp[CHILD_MAX][CANDY_MAX];
void calcPolyDp() {
	polyDp[0][0] = 1;
	FOR(childI, 1, childNum + 1) REP(candyI, candyNum + 1) {
		REP(k, candyI + 1) {
			IntType childISum = (((powAccumSum[candyI - k][hasyagis[1][childI]] - powAccumSum[candyI - k][hasyagis[0][childI] - 1]) % mod) + mod) % mod;
			polyDp[childI][candyI] += polyDp[childI - 1][k] * childISum;
			polyDp[childI][candyI] %= mod;
		}
	}
}
int main() {
	cin >> childNum >> candyNum;
	REP(i, 2) FOR(j, 1, childNum + 1) {
		cin >> hasyagis[i][j];
	}
	calcPowAccumSum();
	calcPolyDp();

	cout << polyDp[childNum][candyNum] << endl;

	return 0;
}