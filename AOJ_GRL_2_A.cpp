// AOJ GRL_2_A : Minimum Spanning Tree
// Primñ@Ç∆Kruskalñ@ÇÃÇQí ÇËÇ≈é¿ëï. mainÇ≈êÿÇËë÷Ç¶

#include <cstdio>
#include <iostream>
#include <tuple>
#include <queue>
#include <functional>
#include <list>
#include <algorithm>

using namespace std;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i = (a); i < (b); i++)

const int MAX_NODE_NUM = 10005;
const int MAX_EDGE_NUM = 100005;

namespace Prim {
	static list<tuple<int, int>> adjLists[MAX_NODE_NUM];
	static bool isNodeInST[MAX_NODE_NUM];
	void run() {
		int n, m;
		cin >> n >> m;
		REP(i, m) {
			int w, s, t;
			cin >> s >> t >> w;
			adjLists[s].push_back(make_tuple(w, t));
			adjLists[t].push_back(make_tuple(w, s));
		}

		using EdgeType = tuple<int, int>;
		priority_queue<EdgeType, vector<EdgeType>, greater<EdgeType>> q;
		long long cost = 0;
		int stNodeNum = 0;
		int newNode = 0;
		int newWeight = 0;
		q.push(make_tuple(newWeight, newNode));
		while (stNodeNum < n) {
			tie(newWeight, newNode) = q.top();
			q.pop();
			if (isNodeInST[newNode] == false) {
				isNodeInST[newNode] = true;
				cost += newWeight;
				stNodeNum++;
				for (auto t : adjLists[newNode]) q.push(t);
			}
		}

		cout << cost << endl;

		return;
	}
};

namespace Kruskal {
	using EdgeType = tuple<int, int, int>;
	static EdgeType edges[MAX_EDGE_NUM];
	inline int& w(EdgeType& e) { return get<0>(e); }
	inline int& s(EdgeType& e) { return get<1>(e); }
	inline int& t(EdgeType& e) { return get<2>(e); }
	static int parent[MAX_NODE_NUM];
	int root(int a) { return (parent[a] < 0) ? a : (parent[a] = root(parent[a])); }
	bool unite(int a, int b) {
		int x = root(a), y = root(b);
		if (x == y) return false;
		if (parent[y] < parent[x]) swap(x, y);
		parent[x] += parent[y];
		parent[y] = x;
		return true;
	}
	void run() {
		int n, m;
		cin >> n >> m;
		REP(i, m) cin >> s(edges[i]) >> t(edges[i]) >> w(edges[i]);
		sort(edges, edges + m);
		REP(i, n) parent[i] = -1;
		long long cost = 0;
		REP(i, m) if (unite(s(edges[i]), t(edges[i]))) cost += w(edges[i]);
		
		cout << cost << endl;
	}
};

int main() {
	//	Prim::run();
	Kruskal::run();

	return 0;
}
