#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FORCLS(i,a,b) for(int i = (a); i <= (b); i++)
#define REPCLS(i,n) FORCLS(i,1,n)

using IntType = long long;
const IntType mod = 1000000007ll;
const IntType MAX_HEIGHT = 1000000005ll;
const int MAX_N = 100005;
int n;
IntType t[MAX_N];
IntType a[MAX_N];
IntType hs[MAX_N];

int main() {
	cin >> n;
	REPCLS(i, n) cin >> t[i];
	REPCLS(i, n) cin >> a[i];

	t[0] = 0;	t[n + 1] = MAX_HEIGHT;
	a[0] = MAX_HEIGHT;	a[n + 1] = 0;

	REPCLS(i, n) {
		bool chgT = t[i - 1] < t[i];
		bool chgA = a[i] > a[i + 1];
		if (chgT && chgA) {
			if (t[i] == a[i]) hs[i] = 1;
			else hs[i] = 0;
		}
		else if (chgT && !chgA) {
			if (t[i] <= a[i]) hs[i] = 1;
			else hs[i] = 0;
		}
		else if (!chgT && chgA) {
			if (a[i] <= t[i]) hs[i] = 1;
			else hs[i] = 0;
		}
		else {
			hs[i] = min(t[i], a[i]);
		}
	}

	IntType ans = 1;
	REPCLS(i, n) {
		ans = (ans * hs[i]) % mod;
	}

	cout << ans << endl;

	return 0;
}