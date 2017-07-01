// ARC058-E
// 参考 hirokazu1020
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <array>
#include <cmath>

using namespace std;

const int A_MAX = 10; // a_iの範囲
const int X_MAX = 5;
const int Y_MAX = 7;
const int Z_MAX = 5;
const int XYZ_MAX = X_MAX + Y_MAX + Z_MAX;
const int STATE_MAX = 1 << (XYZ_MAX - 1);
const int N_MAX = 41;
using Int = long long;
const Int mod = 1000000007ull;

const vector<Int> n2allPatternNum = [] {
	vector<Int> v; v.resize(N_MAX);
	v[0] = 1;
	for (int i = 1; i < N_MAX; i++) {
		v[i] = (v[i - 1] * A_MAX) % mod;
	}
	return v;
}();

int arrayLengthN;
int haikuX, haikuY, haikuZ;
int stateNum;
Int dpNonXYZ[N_MAX][STATE_MAX]; // 長さn,先頭の数値列sとなってる,XYZを作らないパターン数
// 先頭の数値列例 1,2,3 -> 1 = 1, 2 = 10, 3 = 100 -> s = 100101

inline int pushBackBits(int bits, int value) {
	return ((bits << value) | (1 << (value - 1)));
}
inline int clampBits(int bits) {
	return bits & ((1 << (haikuX + haikuY + haikuZ - 1)) - 1);
}
inline bool isBitsXYZ(int bits) {
	return
		(bits & (1 << (haikuX - 1))) &&
		(bits & (1 << (haikuX + haikuY - 1))) &&
		(bits & (1 << (haikuX + haikuY + haikuZ - 1)));
}
void countNonXYZ(int n) {
	auto& dpPrev = dpNonXYZ[n - 1];
	auto& dp = dpNonXYZ[n];
	for (int s = 0; s < stateNum; s++) if (dpPrev[s]) {
		for (int a = 1; a <= A_MAX; a++) {
			int t = pushBackBits(s, a);
			if (!isBitsXYZ(t)) {
				dp[clampBits(t)] += dpPrev[s];
				dp[clampBits(t)] %= mod;
			}
		}
	}
}
void countNonXYZ() {
	dpNonXYZ[0][0] = 1;
	for (int i = 1; i <= arrayLengthN; i++) {
		countNonXYZ(i);
	}
}
int main() {
	cin >> arrayLengthN;
	cin >> haikuX >> haikuY >> haikuZ;
	stateNum = 1 << (haikuX + haikuY + haikuZ - 1);
	countNonXYZ();
	Int ans = n2allPatternNum[arrayLengthN];
	for (int s = 0; s < stateNum; s++) {
		ans -= dpNonXYZ[arrayLengthN][s];
	}
	ans %= mod;
	ans += mod;
	ans %= mod;

	cout << ans << endl;

	return 0;
}