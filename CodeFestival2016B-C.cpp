// MST Minimam(cost)Spaning Tree の問題
// MSTは貪欲法でうまくいく。プリム法とかあるけど、
// 結局以下がポイント。
// ・グラフ頂点数nのとき、その上のTreeは辺数n-1
// ・ループを作らないようにn-1本の辺を選べばST
// ・コスト少ない順にn-1本の辺を選べばMST
// プリム法では、探す辺ををすでに選んだ部分木の周りのみでも大丈夫というアルゴリズム。
// 本問題ではxy座標において同一平行の位置の辺のcostが同じなので、小さいところからまとめて選んでく(これをfillとする)。
// xで1箇所fillすると、yではループを作らないでfillするには1本skipすればok。
// 同様に、xでi箇所fillすると、yではループを作らないでfillするにはi本skipすればok。

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <array>
#include <limits>
#include <queue>
#include <functional>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i = (a); i < (b); i++)

using IntType = long long;
const int MAX_SIZE = 100005;
const int INF = 1000000000;
const int X = 0;
const int Y = 1;
IntType pq[2][MAX_SIZE];
int wh[2];

void solve() {
	cin >> wh[X] >> wh[Y];
	for (int x : {X, Y}) {
		REP(i, wh[x]) {
			cin >> pq[x][i];
		}
		pq[x][wh[x]] = INF;
		sort(pq[x], pq[x] + wh[x] + 1);
	}
	int ij[2] = { 0,0 };
	IntType cost = 0;
	while (ij[X] < wh[X] || ij[Y] < wh[Y]) {
		int x = (pq[X][ij[X]] < pq[Y][ij[Y]]) ? X : Y;
		int y = 1 - x;
		cost += pq[x][ij[x]] * (wh[y] + 1 - ij[y]);
		ij[x]++;
	}
	cout << cost << endl;
}

int main() {
	solve();
	return 0;
}