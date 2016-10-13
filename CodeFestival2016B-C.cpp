// MST Minimam(cost)Spaning Tree �̖��
// MST���×~�@�ł��܂������B�v�����@�Ƃ����邯�ǁA
// ���ǈȉ����|�C���g�B
// �E�O���t���_��n�̂Ƃ��A���̏��Tree�͕Ӑ�n-1
// �E���[�v�����Ȃ��悤��n-1�{�̕ӂ�I�ׂ�ST
// �E�R�X�g���Ȃ�����n-1�{�̕ӂ�I�ׂ�MST
// �v�����@�ł́A�T���ӂ������łɑI�񂾕����؂̎���݂̂ł����v�Ƃ����A���S���Y���B
// �{���ł�xy���W�ɂ����ē��ꕽ�s�̈ʒu�̕ӂ�cost�������Ȃ̂ŁA�������Ƃ��납��܂Ƃ߂đI��ł�(�����fill�Ƃ���)�B
// x��1�ӏ�fill����ƁAy�ł̓��[�v�����Ȃ���fill����ɂ�1�{skip�����ok�B
// ���l�ɁAx��i�ӏ�fill����ƁAy�ł̓��[�v�����Ȃ���fill����ɂ�i�{skip�����ok�B

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